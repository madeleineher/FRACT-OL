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

void	douburncolor(t_env *e, t_dou d)
{
	if (d.n == e->xy.nmax)
		*(int *)&e->data[d.x * (e->w.bpp / 8) + d.y * e->w.sl] = \
			e->pal[e->c][0];
	else
		*(int *)&e->data[d.x * (e->w.bpp / 8) + d.y * e->w.sl] = \
			e->pal[e->c][d.n % 5];
}

void	prelimdouburn(t_env *e, t_dou *d)
{
	d->y = -1;
	d->ty = e->xy.ymin;
	d->dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	d->dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
}

void	doubleburn(t_env *e, t_dou d)
{
	prelimdouburn(e, &d);
	while (++d.y < HEIGHT)
	{
		d.tx = e->xy.xmin;
		d.x = -1;
		while (++d.x < WIDTH)
		{
			d.a = d.tx;
			d.b = d.ty;
			d.n = -1;
			while (++d.n < e->xy.nmax)
			{
				d.two_ab = d.a * d.a - d.b * d.b + d.tx;
				d.b = -2 * d.a * fabs(d.b) + d.ty;
				d.a = d.two_ab;
				if (d.a * d.a + d.b * d.b > 16.0)
					break ;
			}
			douburncolor(e, d);
			d.tx += d.dx;
		}
		d.ty += d.dy;
	}
}
