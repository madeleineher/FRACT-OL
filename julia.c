/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/10 10:57:34 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	juliasetup(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.n = 0;
	e->j.nmax = 1000;
	e->j.w = 5;
	e->j.h = (e->j.w * HEIGHT) / WIDTH;
	e->j.xmin = -e->j.w/2;
	e->j.xmax = e->j.xmin + e->j.w;
	e->j.ymin = -e->j.h/2;
	e->j.ymax = e->j.ymin + e->j.h;
	e->j.dx = (e->j.xmax - e->j.xmin) / (WIDTH);
	e->j.dy = (e->j.ymax - e->j.ymin) / (HEIGHT);
	e->j.tx = 0;
	e->j.ty = e->j.ymin;
}

void	juliacolor(t_env *e)
{
	if (e->j.n == e->j.nmax)
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] 
			= 0x0000FF; //map(e);
	else
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl]
		   	= e->j.n * 0xFF0000; //map(e);
}

void	julia(t_env *e)
{
	juliasetup(e);
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
				e->j.a = e->j.two_a - e->j.two_b - 0.7269;
				e->j.b = e->j.two_ab + 0.1889;
				if (e->j.a * e->j.a + e->j.b * e->j.b > 16.0)
					break;
			}
			juliacolor(e);
			e->j.tx += e->j.dx;
		}
		e->j.x = -1;
		e->j.ty += e->j.dy;
	}
}
