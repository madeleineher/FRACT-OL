/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 16:39:17 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	juliacolor(t_env *e)
{
	if (e->j.n == e->xy.nmax)
	{
		e->data[0 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10];
		e->data[1 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10] >> 8;
		e->data[2 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10] >> 16;
		e->data[3 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = 0;
	}
	else
	{
		e->data[0 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10000];
		e->data[1 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10000] >> 8;
		e->data[2 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = \
			e->colgrad[e->j.n % 10000] >> 16;
		e->data[3 + e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl] = 0;
	}
}

void	map(t_env *e)
{
	e->xy.mre = ((double)e->mo.mx / (WIDTH / (e->xy.xmax - e->xy.xmin)) + \
		e->xy.xmin);
	e->xy.mri = ((double)e->mo.my / (HEIGHT / (e->xy.ymax - e->xy.ymin)) + \
		e->xy.ymin);
}

void	julia(t_env *e)
{
	e->j.y = -1;
	while (++e->j.y < HEIGHT)
	{
		e->j.x = -1;
		while (++e->j.x < WIDTH)
		{
			e->j.a = e->xy.xmin + ((double)e->j.x * e->xy.w_t / WIDTH);
			e->j.b = e->xy.ymin + ((double)e->j.y * e->xy.h_t / HEIGHT);
			e->j.n = -1;
			while (++e->j.n < e->xy.nmax)
			{
				e->j.two_a = e->j.a * e->j.a;
				e->j.two_b = e->j.b * e->j.b;
				e->j.two_ab = 2.0 * e->j.a * e->j.b;
				if (e->k[KEY_SPACEBAR] != 1)
					map(e);
				e->j.a = e->j.two_a - e->j.two_b + e->xy.mre;
				e->j.b = e->j.two_ab + e->xy.mri;
				if (e->j.a * e->j.a + e->j.b * e->j.b > 16.0)
					break ;
			}
			juliacolor(e);
		}
	}
}
