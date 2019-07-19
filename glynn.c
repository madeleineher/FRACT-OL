/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:16:53 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/17 14:16:55 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	glynncolor(t_env *e)
{
	if (e->g.n == e->xy.nmax)
	{
		e->data[0 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->m.n % 10];
		e->data[1 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->m.n % 10] >> 8;
		e->data[2 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->m.n % 10] >> 16;
		e->data[3 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = 0;
	}
	else
	{
		e->data[0 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->g.n % 1000];
		e->data[1 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->g.n % 1000] >> 8;
		e->data[2 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = \
			e->colgrad[e->g.n % 1000] >> 16;
		e->data[3 + e->g.x * (e->w.bpp / 8) + e->g.y * e->w.sl] = 0;
	}
}

void	glynn(t_env *e)
{
	e->g.y = -1;
	while (++e->g.y < HEIGHT)
	{
		e->g.x = -1;
		while (++e->g.x < WIDTH)
		{
			e->g.a = e->xy.xmin + ((double)e->g.x * e->xy.w_t / WIDTH);
			e->g.b = e->xy.ymin + ((double)e->g.y * e->xy.h_t / HEIGHT);
			e->g.n = -1;
			e->g.cmplx = CMPLX(e->g.a, e->g.b);
			while (++e->g.n < e->xy.nmax)
			{
				e->g.cmplx = cpow(e->g.cmplx, 1.5) - 0.2;
				if (cabs(e->g.cmplx) >= 16.0)
					break ;
			}
			glynncolor(e);
		}
	}
}
