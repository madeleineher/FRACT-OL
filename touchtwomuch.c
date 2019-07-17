/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touchtwomuch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:39:25 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/09 14:39:27 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		movefractol(t_env *e)
{
	if (e->k[W] == 1 || e->k[S] == 1)
	{
		e->xy.ymin += (e->k[W] ? 0.005 : -0.005);
		e->xy.ymax += (e->k[W] ? 0.005 : -0.005);
		blackout(e);
	}
	if (e->k[A] == 1 || e->k[D] == 1)
	{
		e->xy.xmin += (e->k[A] ? 0.005 : -0.005);
		e->xy.xmax += (e->k[A] ? 0.005 : -0.005);
		blackout(e);
	}
	return (0);
}

int		changefractol(t_env *e)
{
	int		i;
	char	*fractols[9];

	i = -1;
	fractols[0] = "julia";
	fractols[1] = "mandelbrot";
	fractols[2] = "fern";
	fractols[3] = "burning";
	fractols[4] = "tricorn";
	fractols[5] = "koch";
	fractols[6] = "sierpinski";
	fractols[7] = "doubleburning";
	fractols[8] = "glynn";
	e->oldfrac = e->fractol;
	while (fractols[++i][0] != e->fractol[0])
		;
	if (i < 8)
		i++;
	else
		i = 0;
	e->fractol = fractols[i];
	e->k[N] = 0;
	setfractol(e);
	blackout(e);
	return (0);
}

int		reset(t_env *e)
{
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / HEIGHT;
	e->xy.xmin = (e->fractol[0] == 'f' ? -2.182 : -e->xy.w / 2);
	e->xy.xmax = (e->fractol[0] == 'f' ? 2.6558 : e->xy.xmin + e->xy.w);
	e->xy.ymin = (e->fractol[0] == 'f' ? 0 : -e->xy.h / 2);
	e->xy.ymax = (e->fractol[0] == 'f' ? 9.9983 : e->xy.ymin + e->xy.h);
	e->xy.w_t = (e->xy.xmax - e->xy.xmin);
	e->xy.h_t = (e->xy.ymax - e->xy.ymin);
	if (e->fractol[0] == 's')
	{
		e->xy.xmin = 0;
		e->xy.xmax = WIDTH;
		e->xy.ymin = 0;
		e->xy.ymax = HEIGHT;
	}
	if (e->fractol[0] == 'k')
	{
		e->xy.xmin = WIDTH / 4;
		e->xy.xmax = WIDTH / 4 * 3;
		e->xy.ymin = HEIGHT / 4;
		e->xy.ymax = HEIGHT / 4 * 3;
	}
	blackout(e);
	return (0);
}

int		touchtwomuch(t_env *e)
{
	if (e->k[R] == 1)
		reset(e);
	if (e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1 || e->k[D] == 1)
		movefractol(e);
	if (e->k[N] == 1)
		changefractol(e);
	return (0);
}
