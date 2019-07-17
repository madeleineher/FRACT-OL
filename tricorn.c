/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:14:54 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/09 14:14:57 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	tricorncolor(t_env *e)
{
	if (e->t.n == e->xy.nmax)
	{
		e->data[0 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = 0;
		e->data[1 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][0] >> 8;
		e->data[2 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][0] >> 16;
		e->data[3 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][0] >> 24;
	}
	else
	{
		e->data[0 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = 0;
		e->data[1 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->colgrad[e->t.n % 1000] >> 8;
		e->data[2 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->colgrad[e->t.n % 1000] >> 16;
		e->data[3 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->colgrad[e->t.n % 1000] >> 24;
	}
}

void	tricorn(t_env *e)
{
	e->t.y = -1;
	while (++e->t.y < HEIGHT)
	{
		e->t.x = -1;
		while (++e->t.x < WIDTH)
		{
			e->t.a = 0;
			e->t.b = 0;
			e->t.tx = e->xy.xmin + ((double)e->t.x * e->xy.w_t / WIDTH);
			e->t.ty = e->xy.ymin + ((double)e->t.y * e->xy.h_t / HEIGHT);
			e->t.n = -1;
			while (++e->t.n < e->xy.nmax)
			{
				e->t.two_ab = e->t.a * e->t.a - e->t.b * e->t.b + e->t.tx;
				e->t.b = -2 * e->t.a * e->t.b + e->t.ty;
				e->t.a = e->t.two_ab;
				if (e->t.a * e->t.a + e->t.b * e->t.b > 16.0)
					break ;
			}
			tricorncolor(e);
		}
	
	}
}
