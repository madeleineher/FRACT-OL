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
		*(int *)&e->data[(int)x * (e->w.bpp / 8) + (int)y * e->w.sl] = \
			e->pal[e->c][i % 5];
}

void	fernpoints(t_fer *f)
{
	f->nx = 0;
	f->ny = 0;
	f->random = (double)rand() / RAND_MAX;
	if (f->random < 0.01)
	{
		f->nx = 0.0;
		f->ny = 0.16 * f->y;
	}
	else if (f->random < 0.85)
	{
		f->nx = 0.85 * f->x + 0.04 * f->y;
		f->ny = -0.04 * f->x + 0.85 * f->y + 1.6;
	}
	else if (f->random < 0.93)
	{
		f->nx = 0.2 * f->x + -0.26 * f->y;
		f->ny = 0.23 * f->x + 0.22 * f->y + 1.6;
	}
	else
	{
		f->nx = -0.15 * f->x + 0.28 * f->y;
		f->ny = 0.26 * f->x + 0.24 * f->y + .44;
	}
	f->x = f->nx;
	f->y = f->ny;
}

void	fern(t_env *e, t_fer f)
{
	int		x;

	x = -1;
	while (++x < e->xy.nmax)
	{
		fernpoints(&f);
		drawpoint((int)((f.x - e->xy.xmin) * WIDTH / (e->xy.xmax
						- e->xy.xmin)), HEIGHT - (int)((f.y - e->xy.ymin)
						* HEIGHT / (e->xy.ymax - e->xy.ymin)), e, x);
	}
}
