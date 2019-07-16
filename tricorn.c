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
	// int				amp;
	// double			freq;
	// static int	i = 0;
	// int				center;
	// int 			color;
	
	// color = 0;
	// freq = .3;
	// amp = 127;
	// center = 128;
	// color = sin(freq * i) * amp + center;
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
		e->data[1 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][e->t.n % 5] >> 8;
		e->data[2 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][e->t.n % 5] >> 16;
		e->data[3 + e->t.x * (e->w.bpp / 8) + e->t.y * e->w.sl] = e->pal[e->c][e->t.n % 5] >> 24;
	}
	// i++;
	// if (i >= 32)
	// 	i = 0;
}

// void	prelimtricorn(t_env *e)
// {
// 	e->t.y = -1;
// 	e->t.ty = e->xy.ymin;
// 	e->t.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
// 	e->t.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
// }

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
