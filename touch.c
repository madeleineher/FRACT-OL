/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:37:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 15:23:51 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

double	function(t_env *e)
{
	return (1 / e->xy.zoom);
}

int		touch(t_env *e)
{
	if (e->k[ESC] == 1)
		exit(0);
	if (e->k[Q] == 1 || e->mo.m == 4)
	{
		e->xy.xmin = e->xy.w_t - function(e) / 2;
		e->xy.xmax = e->xy.h_t + function(e) / 2;
		e->xy.ymin = e->xy.w_t - function(e) / 2;
		e->xy.ymax = e->xy.h_t + function(e) / 2;
		printf("zoom out ++++ xmin : [%f] | xmax : [%f] --- ymin : [%f] | ymax : [%f] == zoom : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax, e->xy.zoom);
		e->xy.zoom *= 0.99;
		e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
		e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
		blackout(e);
		e->mo.m = 0;
	}
	if (e->k[E] == 1 || e->mo.m == 5)
	{
		e->xy.xmin = e->xy.w_t - function(e) / 2;
		e->xy.xmax = e->xy.h_t + function(e) / 2;
		e->xy.ymin = e->xy.w_t - function(e) / 2;
		e->xy.ymax = e->xy.h_t + function(e) / 2;
		printf("zoom in +++ xmin : [%f] | xmax : [%f] --- ymin : [%f] | ymax : [%f] == zoom : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax, e->xy.zoom);
		e->xy.zoom /= 0.99;
		e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
		e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
		if (e->fractol[0] == 'f')
			e->xy.nmax += 10000;
		blackout(e);
		e->mo.m = 0;
	}
	if (e->k[C] == 1)
	{
		e->c = (e->c < 8 ? e->c + 1 : 0);
		blackout(e);
	}
	if (e->k[R] == 1)
	{
		e->xy.w = 5;
		e->xy.zoom = 1.0;
		e->xy.h = (e->xy.w * HEIGHT) / HEIGHT;
		e->xy.xmin = (e->fractol[0] == 'f' ? -2.182 : -e->xy.w / 2);
		e->xy.xmax = (e->fractol[0] == 'f' ? 2.6558 : e->xy.xmin + e->xy.w);
		e->xy.ymin = (e->fractol[0] == 'f' ? 0 : -e->xy.h / 2);
		e->xy.ymax = (e->fractol[0] == 'f' ? 9.9983 : e->xy.ymin + e->xy.h);
		blackout(e);
	}
	if (e->k[W] == 1 || e->k[S] == 1)
	{
		e->xy.h_t = (e->k[S] ? (e->xy.ymax - e->xy.ymin) * 0.005 : -(e->xy.ymax - e->xy.ymin) * 0.005);
		e->xy.ymin += e->xy.h_t;
		e->xy.ymax += e->xy.h_t;
		blackout(e);
		if (e->k[W] == 1)
			printf("UP : val [%f]\n", e->xy.h_t);
		else
			printf("DOWN : val [%f]\n", e->xy.h_t);
	}
	if (e->k[A] == 1 || e->k[D] == 1)
	{
		e->xy.w_t = (e->k[A] ? (e->xy.xmax - e->xy.xmin) * 0.005 : -(e->xy.xmax - e->xy.xmin) * 0.005);
		e->xy.xmin += e->xy.w_t;
		e->xy.xmax += e->xy.w_t;
		blackout(e);
		if (e->k[A] == 1)
			printf("LEFT : val [%f]\n", e->xy.w_t);
		else
			printf("RIGHT : val [%f]\n", e->xy.w_t);
	}
	if (e->k[I] == 1 || e->k[U] == 1)
	{
		e->xy.nmax += (e->k[I] == 1 && e->fractol[0] != 'f' ? 100 : -100);
		e->xy.nmax += (e->k[I] == 1 ? 10000 : -1000);
		if (e->xy.nmax < 0 || e->xy.nmax > 2147480000)
			e->xy.nmax = 100;
		printf("max : [%d]\n", e->xy.nmax);
		blackout(e);
	}
	return (0);
}
