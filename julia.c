/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
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
		   	= e->pal[2][e->j.n % 5];
}

float	mapj(int m, int i, t_env *e)
{
	//start2 + (stop2 - start2 * ((m - start1) / (stop1 - start1))
	if (i == 1)
	{
		if (e->mo.mx < WIDTH / 2)
			return (-0.9 + (0.9 - -0.9 * ((m - 0) / (float)((-WIDTH / 2) - 0)))); 
		else if (e->mo.mx > WIDTH / 2)
			return (-0.9 + (0.9 - -0.9 * ((m - (WIDTH / 2)) / (float)((WIDTH - (WIDTH / 2))))));
	}
	else
	{
		if (e->mo.my < HEIGHT / 2)
			return (-0.9 + (0.9 - -0.9 * ((m - 0) / (float)((-HEIGHT / 2) - 0))));
		else if (e->mo.my > HEIGHT / 2)
			return (-0.9 + (0.9 - -0.9 * ((m - (HEIGHT / 2)) / (float)((HEIGHT - (HEIGHT / 2))))));
	}
	return (0);
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
				e->j.a = e->j.two_a - e->j.two_b + mapj(e->mo.my, 1, e);
				e->j.b = e->j.two_ab + mapj(e->mo.my, 2, e);
				tst = mapj(e->mo.my, 2, e);
				if (e->j.a * e->j.a + e->j.b * e->j.b > 16.0)
					break;
			}
			juliacolor(e);
			e->j.tx += e->j.dx;
		}
		e->j.x = -1;
		e->j.ty += e->j.dy;
	}
	printf("real : [%f] -- imag : [%f] -- test : [%f]\n", e->j.a, e->j.b, tst);
}
