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

void	drawsierpinski(int x, int y, t_env *e, int c)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)&e->data[x * (e->w.bpp / 8) + y * e->w.sl]
			= c;
}

int		lerp(int start, int stop, double amt)
{
	return (start + amt * (stop - start));
}

void	sierpinski(t_env *e, t_sie s)
{
	int	i = -1;
	int	c = 0x000000;

	s.rx = rand() / WIDTH;
	s.ry = rand() / HEIGHT;
	e->xy.nmax = 100000;
	e->s.ax = e->xy.xmax / 2;
	e->s.ay = e->xy.ymin;
	e->s.bx = e->xy.xmin;
	e->s.by = e->xy.ymax;
	e->s.cx = e->xy.xmax;
	e->s.cy = e->xy.ymax;
	while (++i < e->xy.nmax)
	{
		s.r = (int)rand() % 4;
		if (s.r == 0)
		{
			s.rx = lerp(s.rx, s.ax, 0.5);
			s.ry = lerp(s.ry, s.ay, 0.5);
			c = e->pal[e->c][i % 5];
		}
		else if (s.r == 1)
		{
			s.rx = lerp(s.rx, s.bx, 0.5);
			s.ry = lerp(s.ry, s.by, 0.5);
			c = e->pal[e->c][i % 5];
		}
		else if (s.r == 2)
		{
			s.rx = lerp(s.rx, s.cx, 0.5);
			s.ry = lerp(s.ry, s.cy, 0.5);
			c = e->pal[e->c][i % 5];
		}
		drawsierpinski(s.rx, s.ry, e, c);
	}
}
