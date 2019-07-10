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

// printf("zoom out ++++ xmin : [%f] | xmax : [%f] --- ymin : [%f] | ymax : [%f] == zoom : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax, e->xy.zoom);
// printf("zoom in +++ xmin : [%f] | xmax : [%f] --- ymin : [%f] | ymax : [%f] == zoom : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax, e->xy.zoom);

double	function(t_env *e)
{
	return (1 / e->xy.zoom);
}

int		fernzoom(t_env *e)
{
	if ((e->k[Q] == 1 || e->mo.m == 4) && e->fractol[0] == 'f')
	{
		e->xy.xmin /= 0.99; 
		e->xy.xmax /= 0.99;
		e->xy.ymin /= 0.99;
		e->xy.ymax /= 0.99;
		blackout(e);
		e->mo.m = 0;
	}
	if ((e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] == 'f')
	{
		e->xy.xmin *= 0.99; 
		e->xy.xmax *= 0.99;
		e->xy.ymin *= 0.99;
		e->xy.ymax *= 0.99;
		e->xy.nmax += 1000;
		blackout(e);
		e->mo.m = 0;
	}
	return (0);
}

int		zoom(t_env *e)
{
	if ((e->k[Q] == 1 || e->mo.m == 4) && e->fractol[0] != 'f')
	{
		e->xy.xmin = e->xy.w_t - function(e) / 2;
		e->xy.xmax = e->xy.h_t + function(e) / 2;
		e->xy.ymin = e->xy.w_t - function(e) / 2;
		e->xy.ymax = e->xy.h_t + function(e) / 2;
		e->xy.zoom *= 0.99;
		e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
		e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
		blackout(e);
		printf("hello\n");
		e->mo.m = 0;
	}
	if ((e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] != 'f')
	{
		e->xy.xmin = e->xy.w_t - function(e) / 2;
		e->xy.xmax = e->xy.h_t + function(e) / 2;
		e->xy.ymin = e->xy.w_t - function(e) / 2;
		e->xy.ymax = e->xy.h_t + function(e) / 2;
		e->xy.zoom /= 0.99;
		e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
		e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
		blackout(e);
		e->mo.m = 0;
	}
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
	}
	if (e->k[I] == 1 || e->k[U] == 1)
	{
		e->xy.nmax += ((e->k[I] == 1 && e->fractol[0] != 'f') ? 100 : -100);
		if (e->fractol[0] == 'f')
			e->xy.nmax += (e->k[I] == 1 ? 1000 : -1000);
		if (e->xy.nmax < 0 || e->xy.nmax > 2147480000)
			e->xy.nmax = 10000;
		if (e->fractol[0] == 'k')
			e->o.iter += (e->o.iter > 3 && e->o.iter < 13 && e->k[I] == 1 ? 1 : -1);
		blackout(e);
	}
	if ((e->k[Q] == 1 || e->mo.m == 4 || e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] != 'f')
		zoom(e);
	if ((e->k[Q] == 1 || e->mo.m == 4 || e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] == 'f')
		fernzoom(e);
	// if (e->k[KEY_SPACEBAR])
	// {
	// 	printf("hello\n");
	// 	e->k[KEY_SPACEBAR] = 1;
	// }
	if (e->k[R] == 1 || e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1 || e->k[D] == 1 || e->k[N])
		touchtwomuch(e);
	return (0);
}
