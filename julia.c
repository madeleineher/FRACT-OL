/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 16:33:46 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	juliacolor(t_env *e)
{
	if (e->j.n == e->j.nmax)
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = 0x0000FF;
	else
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl]
		   	= e->pal[e->c][e->j.n % 5];
}

float	mapj(int m)
{
	//start2 + (stop2 - start2 * ((m - start1) / (stop1 - start1))
	//map(mouse, 0, width, -1, 1);
	return (-1 + (1 - -1) * ((m - 0) / (float)((WIDTH - 0))));
}

void	julia(t_env *e)
{
	double tst;

	tst = 0;
	e->j.x = -1;
	e->j.y = -1;
	e->j.ty = e->j.ymin;
	while (++e->j.y < HEIGHT)
	{
		e->j.tx = e->j.xmin;
		while (++e->j.x < WIDTH)
		{
			e->j.a = e->j.tx;
			e->j.b = e->j.ty;
			e->j.n = -1;
			while (++e->j.n < e->j.nmax)
			{
				e->j.two_a = e->j.a * e->j.a;
				e->j.two_b = e->j.b * e->j.b;
				e->j.two_ab = 2.0 * e->j.a * e->j.b;
				e->j.a = e->j.two_a - e->j.two_b + mapj(e->mo.mx);
				e->j.b = e->j.two_ab + mapj(e->mo.my);
				tst = mapj(e->mo.mx);
				if (e->j.a * e->j.a + e->j.b * e->j.b > 16.0)
					break;
			}
			juliacolor(e);
			e->j.tx += e->j.dx;
		}
		e->j.x = -1;
		e->j.ty += e->j.dy;
	}
//	printf("real : [%f] -- imag : [%f] -- test : [%f]\n", e->j.a, e->j.b, tst);
}
