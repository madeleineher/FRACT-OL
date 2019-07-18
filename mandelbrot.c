/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 16:44:41 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelcolor(t_env *e)
{
	if (e->m.n == e->xy.nmax)
	{
		e->data[0 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10];
		e->data[1 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10] >> 8;
		e->data[2 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10] >> 16;
		e->data[3 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = 0;
	}
	else
	{
		e->data[0 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10000];
		e->data[1 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10000] >> 8;
		e->data[2 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = \
			e->colgrad[e->m.n % 10000] >> 16;
		e->data[3 + e->m.x * (e->w.bpp / 8) + e->m.y * e->w.sl] = 0;
	}
}

void	mandelbrot(t_env *e)
{
	e->m.y = -1;
	while (++e->m.y < HEIGHT)
	{
		e->m.x = -1;
		while (++e->m.x < WIDTH)
		{
			e->m.a = 0;
			e->m.b = 0;
			e->m.tx = e->xy.xmin + ((double)e->m.x * e->xy.w_t / WIDTH);
			e->m.ty = e->xy.ymin + ((double)e->m.y * e->xy.h_t / HEIGHT);
			e->m.n = -1;
			while (++e->m.n < e->xy.nmax)
			{
				e->m.two_a = e->m.a * e->m.a;
				e->m.two_b = e->m.b * e->m.b;
				e->m.two_ab = 2.0 * e->m.a * e->m.b;
				e->m.a = e->m.two_a - e->m.two_b + e->m.tx;
				e->m.b = e->m.two_ab + e->m.ty;
				if (e->m.a * e->m.a + e->m.b * e->m.b > 16.0)
					break ;
			}
			mandelcolor(e);
		}
	}
}
