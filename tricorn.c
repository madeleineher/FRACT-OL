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
	if (t.n == e->xy.nmax)
		*(int *)&e->data[t.x * (e->w.bpp / 8) + t.y * e->w.sl] = \
				e->pal[e->c][0];
	else
		*(int *)&e->data[t.x * (e->w.bpp / 8) + t.y * e->w.sl] = \
			e->pal[e->c][t.n % 5];
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
