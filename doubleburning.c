/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleburning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:39:34 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/11 19:39:36 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	douburncolor(t_env *e)
{
	if (e->d.n == e->xy.nmax)
	{
		e->data[0 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10];
		e->data[1 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10] >> 8;
		e->data[2 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10] >> 16;
		e->data[3 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = 0;
	}
	else
	{
		e->data[0 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10000];
		e->data[1 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10000] >> 8;
		e->data[2 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = \
			e->colgrad[e->d.n % 10000] >> 16;
		e->data[3 + e->d.x * (e->w.bpp / 8) + e->d.y * e->w.sl] = 0;
	}
}

void	doubleburn(t_env *e)
{
	e->d.y = -1;
	while (++e->d.y < HEIGHT)
	{
		e->d.x = -1;
		while (++e->d.x < WIDTH)
		{
			e->d.a = 0;
			e->d.b = 0;
			e->d.tx = e->xy.xmin + ((double)e->d.x * e->xy.w_t / WIDTH);
			e->d.ty = e->xy.ymin + ((double)e->d.y * e->xy.h_t / HEIGHT);
			e->d.n = -1;
			while (++e->d.n < e->xy.nmax)
			{
				e->d.two_ab = e->d.a * e->d.a - e->d.b * e->d.b + e->d.tx;
				e->d.b = -2 * e->d.a * fabs(e->d.b) + e->d.ty;
				e->d.a = e->d.two_ab;
				if (e->d.a * e->d.a + e->d.b * e->d.b > 16.0)
					break ;
			}
			douburncolor(e);
		}
	}
}
