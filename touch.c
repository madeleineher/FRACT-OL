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

// int		fernzoom(t_env *e)
// {
// 	if ((e->k[Q] == 1 || e->mo.m == 4) && e->fractol[0] == 'f')
// 	{
// 		e->xy.xmin /= 0.99; 
// 		e->xy.xmax /= 0.99;
// 		e->xy.ymin /= 0.99;
// 		e->xy.ymax /= 0.99;
// 		blackout(e);
// 		e->mo.m = 0;
// 	}
// 	if ((e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] == 'f')
// 	{
// 		e->xy.xmin *= 0.99; 
// 		e->xy.xmax *= 0.99;
// 		e->xy.ymin *= 0.99;
// 		e->xy.ymax *= 0.99;
// 		e->xy.nmax += 1000;
// 		blackout(e);
// 		e->mo.m = 0;
// 	}
// 	return (0);
// }

int		zoom(t_env *e)
{
	double oldrange_x;
	double oldrange_y;

	// oldrange_x = 0;
	// oldrange_y = 0;
	if ((e->k[Q] == 1 || e->mo.m == 4) && e->fractol[0])
	{
		e->xy.txmin = e->xy.xmin;
		e->xy.tymin = e->xy.ymin;
		oldrange_x = (e->xy.xmax - e->xy.xmin);
		oldrange_y = (e->xy.ymax - e->xy.ymin);
		e->xy.w_t = oldrange_x / (3./4.);
		e->xy.h_t = oldrange_y / (3./4.);
		e->xy.xmin = e->xy.txmin + ((double)e->mo.mx / (double)WIDTH) * (oldrange_x - e->xy.w_t);
		e->xy.xmax = e->xy.xmin + e->xy.w_t;
		e->xy.ymin = e->xy.tymin + ((double)e->mo.my / (double)WIDTH) * (oldrange_y - e->xy.h_t);
		e->xy.ymax = e->xy.ymin + e->xy.h_t;
		blackout(e);
		e->mo.m = 0;
	}
	if ((e->k[E] == 1 || e->mo.m == 5) && e->fractol[0])
	{
		e->xy.txmin = e->xy.xmin;
		e->xy.tymin = e->xy.ymin;
		oldrange_x = (e->xy.xmax - e->xy.xmin);
		oldrange_y = (e->xy.ymax - e->xy.ymin);
		e->xy.w_t = oldrange_x * 3./4.;
		e->xy.h_t = oldrange_y * 3./4.;
		e->xy.xmin = e->xy.txmin + ((double)e->mo.mx / (double)WIDTH) * (oldrange_x - e->xy.w_t);
		e->xy.xmax = e->xy.xmin + e->xy.w_t;
		e->xy.ymin = e->xy.tymin + ((double)e->mo.my / (double)WIDTH) * (oldrange_y - e->xy.h_t);
		e->xy.ymax = e->xy.ymin + e->xy.h_t;
		// e->xy.zoom *= 0.99;
		blackout(e);
		printf("(%d,%d) : x / width = %lf, y / height = %lf\n", e->mo.mx, e->mo.my,
				(double)e->mo.mx / (double)WIDTH,
				(double)e->mo.my / (double)HEIGHT);
		printf("x : [%f, %f], range_dist : %f\n",
				e->xy.xmin,
				e->xy.xmax,
				e->xy.w_t);
		printf("y : [%f, %f], range_dist : %f\n",
				e->xy.ymin,
				e->xy.ymax,
				e->xy.h_t);		
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
	if ((e->k[Q] == 1 || e->mo.m == 4 || e->k[E] == 1 || e->mo.m == 5))
		zoom(e);
	// if ((e->k[Q] == 1 || e->mo.m == 4 || e->k[E] == 1 || e->mo.m == 5) && e->fractol[0] == 'f')
	// 	fernzoom(e);
	// if (e->k[KEY_SPACEBAR])
	// {
	// 	printf("hello\n");
	// 	e->k[KEY_SPACEBAR] = 1;
	// }
	if (e->k[R] == 1 || e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1 || e->k[D] == 1 || e->k[N])
		touchtwomuch(e);
	return (0);
}
