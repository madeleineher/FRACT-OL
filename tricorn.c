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

void	tricorncolor(t_env *e, t_tri t)
{
	int				amp;
	double			freq;
	static int	i = 0;
	int				center;
	int 			color;
	
	color = 0;
	freq = .3;
	amp = 127;
	center = 128;
	color = sin(freq * i) * amp + center;
	if (t.n == e->xy.nmax)
	{
		e->data[0 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = 0;
		e->data[1 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = e->pal[e->c][0] >> 8;
		e->data[2 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = e->pal[e->c][0] >> 16;
		e->data[3 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = e->pal[e->c][0] >> 24;
	}
	else
	{
		e->data[0 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = 0;
		e->data[1 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = color;
		e->data[2 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = color;
		e->data[3 + t.x * (e->w.bpp / 8) + t.y * e->w.sl] = color;
	}
	i++;
	if (i >= 32)
		i = 0;
}

void	prelimtricorn(t_env *e, t_tri *t)
{
	t->y = -1;
	t->ty = e->xy.ymin;
	t->dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	t->dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
}

void	tricorn(t_env *e, t_tri t)
{
	prelimtricorn(e, &t);
	while (++t.y < HEIGHT)
	{
		t.tx = e->xy.xmin;
		t.x = -1;
		while (++t.x < WIDTH)
		{
			t.a = t.tx;
			t.b = t.ty;
			t.n = -1;
			while (++t.n < e->xy.nmax)
			{
				t.two_ab = t.a * t.a - t.b * t.b + t.tx;
				t.b = -2 * t.a * t.b + t.ty;
				t.a = t.two_ab;
				if (t.a * t.a + t.b * t.b > 16.0)
					break ;
			}
			tricorncolor(e, t);
			t.tx += t.dx;
		}
		t.ty += t.dy;
	}
}
