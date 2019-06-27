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
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl]
			= e->pal[e->c][0];
	else
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl]
			= e->pal[e->c][e->j.n % 5];
}

float	map(int m)
{
	//start2 + (stop2 - start2 * ((m - start1) / (stop1 - start1))
	//map(mouse, 0, width, -1, 1);
	return (-1 + (1 - -1) * ((m - 0) / (float)((WIDTH - 0))));
}

void	whilejulia(t_env *e)
{
	while (++e->j.n < e->j.nmax)
	{
		e->j.two_a = e->j.a * e->j.a;
		e->j.two_b = e->j.b * e->j.b;
		e->j.two_ab = 2.0 * e->j.a * e->j.b;
		e->j.a = e->j.two_a - e->j.two_b + map(e->mo.mx);
		e->j.b = e->j.two_ab + map(e->mo.my);
		if (e->j.a * e->j.a + e->j.b * e->j.b > 16.0)
			break;
	}
}

void	julia(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.ty = e->xy.ymin;
	while (++e->j.y < HEIGHT)
	{
		e->j.tx = e->xy.xmin;
		while (++e->j.x < WIDTH)
		{
			e->j.a = e->j.tx;
			e->j.b = e->j.ty;
			e->j.n = -1;
			whilejulia(e);
			juliacolor(e);
			e->j.tx += e->j.dx;
		}
		e->j.x = -1;
		e->j.ty += e->j.dy;
	}
}
