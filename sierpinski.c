/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:36:13 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 12:19:38 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	drawsierpinski(int x, int y, t_env *e, int i)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		e->data[0 + x * (e->w.bpp / 8) + y * e->w.sl] = 0;
		e->data[1 + x * (e->w.bpp / 8) + y * e->w.sl] = e->colgrad[i % 1000] >> 8;
		e->data[2 + x * (e->w.bpp / 8) + y * e->w.sl] = e->colgrad[i % 1000] >> 8;
		e->data[3 + x * (e->w.bpp / 8) + y * e->w.sl] = e->colgrad[i % 1000] >> 8;
	}
}

int		lerp(int start, int stop, double amt)
{
	return (start + amt * (stop - start));
}

void	sierpinski(t_env *e)
{
	int	i = -1;

	e->s.rx = rand() / WIDTH;
	e->s.ry = rand() / HEIGHT;
	e->xy.nmax = 100000;
	e->s.ax = e->xy.xmax / 2;
	e->s.ay = e->xy.ymin;
	e->s.bx = e->xy.xmin;
	e->s.by = e->xy.ymax;
	e->s.cx = e->xy.xmax;
	e->s.cy = e->xy.ymax;
	while (++i < e->xy.nmax)
	{
		e->s.r = (int)rand() % 4;
		if (e->s.r == 0)
		{
			e->s.rx = lerp(e->s.rx, e->s.ax, 0.5);
			e->s.ry = lerp(e->s.ry, e->s.ay, 0.5);
		}
		else if (e->s.r == 1)
		{
			e->s.rx = lerp(e->s.rx, e->s.bx, 0.5);
			e->s.ry = lerp(e->s.ry, e->s.by, 0.5);
		}
		else if (e->s.r == 2)
		{
			e->s.rx = lerp(e->s.rx, e->s.cx, 0.5);
			e->s.ry = lerp(e->s.ry, e->s.cy, 0.5);
		}
		drawsierpinski(e->s.rx, e->s.ry, e, i);
	}
}
