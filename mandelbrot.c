/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 15:19:05 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelcolor(t_env *e)
{
	if (e->m.n == e->xy.nmax)
		*(int *)&e->data[e->m.j * (e->w.bpp / 8) + e->m.i * e->w.sl] 
			= e->pal[e->c][0];
	else
		*(int *)&e->data[e->m.j * (e->w.bpp / 8) + e->m.i * e->w.sl]
			= e->pal[e->c][e->m.n % 5];
}

void	mandelbrot(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.ty = e->xy.ymin;
	while (++e->m.i < HEIGHT)
	{
		e->m.tx = e->xy.xmin;
		while (++e->m.j < WIDTH)
		{
			e->m.a = e->m.tx;
			e->m.b = e->m.ty;
			e->m.n = -1;
			while (++e->m.n < e->xy.nmax)
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
