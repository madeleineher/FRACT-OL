/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:57:50 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/04 17:21:43 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	burncolor(t_env *e)
{
	if (e->b.n == e->xy.nmax)
	{
		e->data[0 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10];
		e->data[1 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10] >> 8;
		e->data[2 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10] >> 16;
		e->data[3 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = 0;
	}
	else
	{
		e->data[0 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10000];
		e->data[1 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10000] >> 8;
		e->data[2 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = \
			e->colgrad[e->b.n % 10000] >> 16;
		e->data[3 + e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl] = 0;
	}
}

void	burn(t_env *e)
{
	e->b.y = -1;
	while (++e->b.y < HEIGHT)
	{
		e->b.x = -1;
		while (++e->b.x < WIDTH)
		{
			e->b.a = 0;
			e->b.b = 0;
			e->b.tx = e->xy.xmin + ((double)e->b.x * e->xy.w_t / WIDTH);
			e->b.ty = e->xy.ymin + ((double)e->b.y * e->xy.h_t / HEIGHT);
			e->b.n = -1;
			while (++e->b.n < e->xy.nmax)
			{
				e->b.two_ab = e->b.a * e->b.a - e->b.b * e->b.b + e->b.tx;
				e->b.b = fabs(2 * e->b.a * e->b.b) + e->b.ty;
				e->b.a = fabs(e->b.two_ab);
				if (e->b.a * e->b.a + e->b.b * e->b.b > 16.0)
					break ;
			}
			burncolor(e);
		}
	}
}
