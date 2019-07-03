/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:57:50 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 17:18:30 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	burncolor(t_env *e)
{
	if (e->b.n == e->xy.nmax)
		*(int *)&e->data[e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl]
			= e->pal[e->c][0];
	else
		*(int *)&e->data[e->b.x * (e->w.bpp / 8) + e->b.y * e->w.sl]
			= e->pal[e->c][e->b.n % 5];
}

void	burn(t_env *e)
{
	e->b.y = -1;
	e->b.ty = e->xy.ymin;
	e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	while (++e->b.y < HEIGHT)
	{
		e->b.x = -1;
		e->b.tx = e->xy.xmin;
		while (++e->b.x < WIDTH)
		{
			e->b.a = e->b.tx;
			e->b.b = e->b.ty;
			e->b.n = -1;
			while (++e->b.n < e->xy.nmax)
			{
				e->b.two_a = e->b.a * e->b.a;
				e->b.two_b = e->b.b * e->b.b;
				e->b.two_ab = e->b.a * e->b.a - e->b.b * e->b.b + e->b.tx; //xtemp

				e->b.a = (2 * e->b.a * e->b.b) + e->b.ty;
				e->b.b = (e->b.two_ab);

				if (e->b.a * e->b.a + e->b.b * e->b.b < 4.0)
					break;
			}
			burncolor(e);
			e->b.tx += e->b.dx;
		}
		e->b.ty += e->b.dy;
	}
}
