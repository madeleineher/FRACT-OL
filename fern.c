/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:05:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/04 17:21:46 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	drawpoint(int x, int y, t_env *e, int i)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		e->data[0 + x * (e->w.bpp / 8) + y * e->w.sl] = e->colgrad[i % 10000];
		e->data[1 + x * (e->w.bpp / 8) + y * e->w.sl] = \
			e->colgrad[i % 10000] >> 8;
		e->data[2 + x * (e->w.bpp / 8) + y * e->w.sl] = \
			e->colgrad[i % 10000] >> 8;
		e->data[3 + x * (e->w.bpp / 8) + y * e->w.sl] = 0;
	}
}

void	fernpoints(t_env *e)
{
	e->f.nx = 0;
	e->f.ny = 0;
	e->f.random = (double)rand() / RAND_MAX;
	if (e->f.random < 0.01)
	{
		e->f.nx = 0.0;
		e->f.ny = 0.16 * e->f.y;
	}
	else if (e->f.random < 0.85)
	{
		e->f.nx = 0.85 * e->f.x + 0.04 * e->f.y;
		e->f.ny = -0.04 * e->f.x + 0.85 * e->f.y + 1.6;
	}
	else if (e->f.random < 0.93)
	{
		e->f.nx = 0.2 * e->f.x + -0.26 * e->f.y;
		e->f.ny = 0.23 * e->f.x + 0.22 * e->f.y + 1.6;
	}
	else
	{
		e->f.nx = -0.15 * e->f.x + 0.28 * e->f.y;
		e->f.ny = 0.26 * e->f.x + 0.24 * e->f.y + .44;
	}
	e->f.x = e->f.nx;
	e->f.y = e->f.ny;
}

void	fern(t_env *e)
{
	int		x;

	x = -1;
	while (++x < e->xy.nmax)
	{
		fernpoints(e);
		drawpoint((int)((e->f.x - e->xy.xmin) * WIDTH / (e->xy.xmax - \
			e->xy.xmin)), HEIGHT - (int)((e->f.y - e->xy.ymin) * \
			HEIGHT / (e->xy.ymax - e->xy.ymin)), e, x);
	}
}
