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
	e->xy.oldrange_x = (e->xy.xmax - e->xy.xmin);
	e->xy.oldrange_y = (e->xy.ymax - e->xy.ymin);
	e->xy.w_t = e->xy.oldrange_x / (1. / 1.25);
	e->xy.h_t = e->xy.oldrange_y / (1. / 1.25);
	printf("zoom OUT x : [%f] | zoom y : [%f]\n", e->xy.w_t, e->xy.h_t);
	e->xy.xmin += ((double)e->mo.mx / (double)WIDTH) * \
		(e->xy.oldrange_x - e->xy.w_t);
	e->xy.xmax = e->xy.xmin + e->xy.w_t;
	e->xy.ymin += ((double)e->mo.my / (double)WIDTH) * \
		(e->xy.oldrange_y - e->xy.h_t);
	e->xy.ymax = e->xy.ymin + e->xy.h_t;
	blackout(e);
	e->mo.m = 0;
	return (0);
}

int		zoomin(t_env *e)
{
	double	or_x;
	double 	or_y;
	or_x = e->xy.w_t;
	or_y = e->xy.h_t;
	e->xy.w_t = or_x * 1. / 3.;
	e->xy.h_t = or_y * 1. / 3.;
	printf("zoom IN x : [%.50lf] | zoom y : [%.50lf]\n", e->xy.w_t, e->xy.h_t);
	e->xy.xmin += ((double)e->mo.mx / (double)WIDTH) * \
		(or_x - e->xy.w_t);
	e->xy.xmax = e->xy.xmin + e->xy.w_t;
	e->xy.ymin += ((double)e->mo.my / (double)WIDTH) * \
		(or_y - e->xy.h_t);
	e->xy.ymax = e->xy.ymin + e->xy.h_t;
	blackout(e);
	e->mo.m = 0;
	return (0);
}

int		iterate(t_env *e)
{
	if (e->fractol[0] != 'f' && e->fractol[0] != 'k')
		e->xy.nmax += ((e->k[I] == 1) ? 10 : -10);
	if (e->fractol[0] == 'f')
		e->xy.nmax += (e->k[I] == 1 ? 100 : -100);
	if ((e->xy.nmax < 0 || e->xy.nmax > 2147480000) && e->fractol[0] != 'k')
		e->xy.nmax = 1000;
	if (e->fractol[0] == 'k')
	{
		if (e->k[I] == 1 && (e->xy.nmax >= 0 && e->xy.nmax < 12))
			e->xy.nmax += 1;
		else if (e->k[U] == 1 && (e->xy.nmax > 0 && e->xy.nmax <= 12))
			e->xy.nmax -= 1;
	}
	e->k[I] = 0;
	e->k[U] = 0;
	blackout(e);
	return (0);
}

int		touch(t_env *e)
{
	if (e->k[ESC] == 1)
		exit(0);
	if (e->k[C] == 1)
	{
		e->c = (e->c < 8 ? e->c + 1 : 0);
		blackout(e);
		e->k[C] = 0;
	}
	if (e->k[I] == 1 || e->k[U] == 1)
		iterate(e);
	if (e->k[Q] == 1 || e->mo.m == 4)
		zoomout(e);
	if (e->k[E] == 1 || e->mo.m == 5)
		zoomin(e);
	if (e->k[KEY_SPACEBAR] == 1)
		e->k[KEY_SPACEBAR] = 1;
	if (e->k[R] == 1 || e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1
		|| e->k[D] == 1 || e->k[N])
			touchtwomuch(e);
	return (0);
}
