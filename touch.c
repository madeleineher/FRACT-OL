/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:37:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 15:49:52 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		zoomout(t_env *e)
{
	e->xy.or_x = (e->xy.xmax - e->xy.xmin);
	e->xy.or_y = (e->xy.ymax - e->xy.ymin);
	e->xy.w_t = e->xy.or_x / 0.75;
	e->xy.h_t = e->xy.or_y / 0.75;
	e->xy.xmin += ((double)e->mo.mx / (double)WIDTH) * (e->xy.or_x - e->xy.w_t);
	e->xy.xmax = e->xy.xmin + e->xy.w_t;
	e->xy.ymin += ((double)e->mo.my / (double)WIDTH) * (e->xy.or_y - e->xy.h_t);
	e->xy.ymax = e->xy.ymin + e->xy.h_t;
	e->k[Q] = 0;
	blackout(e);
	e->mo.m = 0;
	return (0);
}

int		zoomin(t_env *e)
{
	e->xy.or_x = e->xy.w_t;
	e->xy.or_y = e->xy.h_t;
	e->xy.w_t = e->xy.or_x * 0.75;
	e->xy.h_t = e->xy.or_y * 0.75;
	e->xy.xmin += ((double)e->mo.mx / (double)WIDTH) * (e->xy.or_x - e->xy.w_t);
	e->xy.xmax = e->xy.xmin + e->xy.w_t;
	e->xy.ymin += ((double)e->mo.my / (double)WIDTH) * (e->xy.or_y - e->xy.h_t);
	e->xy.ymax = e->xy.ymin + e->xy.h_t;
	e->k[E] = 0;
	blackout(e);
	e->mo.m = 0;
	return (0);
}

int		iterate(t_env *e)
{
	e->xy.oldmax = e->xy.nmax;
	if (e->fractol[0] != 'f' && e->fractol[0] != 'k')
		e->xy.nmax += ((e->k[INC] == 1) ? 10 : -10);
	if (e->fractol[0] == 'f')
		e->xy.nmax += (e->k[INC] == 1 ? 100 : -100);
	if ((e->xy.nmax < 0 || e->xy.nmax > 2147480000) && e->fractol[0] != 'k')
		e->xy.nmax = 10;
	if ((e->xy.nmax < 0 || e->xy.nmax > 2147480000) && e->fractol[0] != 'k'\
		&& (e->fractol[0] == 'f' || e->fractol[0] == 's'))
		e->xy.nmax = 10000;
	if (e->fractol[0] == 'k')
	{
		if (e->k[INC] == 1 && (e->xy.nmax >= 0 && e->xy.nmax < 12))
			e->xy.nmax += 1;
		else if (e->k[U] == 1 && (e->xy.nmax > 0 && e->xy.nmax <= 12))
			e->xy.nmax -= 1;
	}
	e->k[INC] = 0;
	e->k[U] = 0;
	blackout(e);
	return (0);
}

int		amplitudeshift(t_env *e)
{
	if (e->k[K] == 1)
	{
		if (e->clr.amp > 50 && e->clr.amp < 129)
			e->clr.amp += 5;
		e->k[K] = 0;
	}
	if (e->k[L] == 1)
	{
		if (e->clr.amp > 50 && e->clr.amp < 129)
			e->clr.amp -= 5;
		e->k[L] = 0;
	}
	if (e->clr.amp < 50 || e->clr.amp >= 127)
		e->clr.amp = 128;
	color(e);
	blackout(e);
	return (0);
}

int		touch(t_env *e)
{
	if (e->k[ESC] == 1)
		exit(0);
	if (e->k[K] == 1 || e->k[L] == 1)
		amplitudeshift(e);
	if (e->k[INC] == 1 || e->k[U] == 1)
		iterate(e);
	if (e->k[Q] == 1 || e->mo.m == 4)
		zoomout(e);
	if (e->k[E] == 1 || e->mo.m == 5)
		zoomin(e);
	if (e->k[KEY_SPACEBAR] == 1)
		e->k[KEY_SPACEBAR] = 1;
	if (e->k[H] == 1)
	{
		e->k[H] = 1;
		texting(e);
	}
	if (e->k[R] == 1 || e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1
		|| e->k[D] == 1 || e->k[N] || e->k[Z] == 1 || e->k[X] == 1
		|| e->k[C] == 1 || e->k[V] == 1 || e->k[B] == 1 || e->k[G] == 1)
		touchtwomuch(e);
	return (0);
}
