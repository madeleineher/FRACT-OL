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

void	burncolor(t_env *e, t_burn b)
{
	if (b.n == e->xy.nmax)
		*(int *)&e->data[b.x * (e->w.bpp / 8) + b.y * e->w.sl]
			= e->pal[e->c][0];
	else
		*(int *)&e->data[b.x * (e->w.bpp / 8) + b.y * e->w.sl]
			= e->pal[e->c][b.n % 5];
}

void	burn(t_env *e, t_burn b)
{
	b.y = -1;
	b.ty = e->xy.ymin;
	b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	while (++b.y < HEIGHT)
	{
		b.tx = e->xy.xmin;
		b.x = -1;
		while (++b.x < WIDTH)
		{
			b.a = b.tx;
			b.b = b.ty;
			b.n = -1;
			while (++b.n < e->xy.nmax)
			{
				b.two_ab = b.a * b.a - b.b * b.b + b.tx;
				b.b = fabs(2 * b.a * b.b) + b.ty;
				b.a = fabs(b.two_ab);
				if (b.a * b.a + b.b * b.b > 16.0)
					break;
			}
			burncolor(e, b);
			b.tx += b.dx;
		}
		b.ty += b.dy;
	}
}
