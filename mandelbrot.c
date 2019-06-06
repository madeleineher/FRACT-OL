/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/06 13:13:37 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelsetup(t_env *e)
{
	e->m.i = -1;
	e->m.j = -1;
	e->m.n = 0;
	e->m.nmax = 1000;
	e->m.w = 5;
	e->m.h = (e->m.w * HEIGHT) / WIDTH;
	e->m.xmin = -e->m.w/2;
	e->m.xmax = e->m.xmin + e->m.w;
	e->m.ymin = -e->m.h/2;
	e->m.ymax = e->m.ymin + e->m.h;
	e->m.dx = (e->m.xmax - e->m.xmin) / (WIDTH);
	e->m.dy = (e->m.ymax - e->m.ymin) / (HEIGHT);
	e->m.tx = 0;
	e->m.ty = e->m.ymin;
}

void	mandelcolor(t_env *e)
{
	if (e->m.n == e->m.nmax)
		*(int *)&e->data[e->m.j * (e->w.bpp / 8) + e->m.i * e->w.sl] = 0x00FF00;
	else
		*(int *)&e->data[e->m.j * (e->w.bpp / 8) + e->m.i * e->w.sl] = 0xFF0000;
}

void	mandelbrot(t_env *e)
{
	mandelsetup(e);
	while (++e->m.i < HEIGHT)
	{
		e->m.tx = e->m.xmin;
		while (++e->m.j < WIDTH)
		{
			e->m.a = e->m.tx;
			e->m.b = e->m.ty;
			e->m.n = -1;
			while (++e->m.n < e->m.nmax)
			{
				e->m.two_a = e->m.a * e->m.a;
				e->m.two_b = e->m.b * e->m.b;
				e->m.two_ab = 2.0 * e->m.a * e->m.b;
				e->m.a = e->m.two_a - e->m.two_b + e->m.tx;
				e->m.b = e->m.two_ab + e->m.ty;
				if (e->m.a * e->m.a + e->m.b * e->m.b > 16.0)
					break;
			}
			mandelcolor(e);
			e->m.tx += e->m.dx;
		}
		e->m.j = -1;
		e->m.ty += e->m.dy;
	}
}
