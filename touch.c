/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:37:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 16:36:39 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		touch(t_env *e)
{
	int	tx;
	int	ty;

	if (e->k[ESC] == 1)
		exit(0);
	if (e->k[Q] == 1 || e->mo.m == 4)
	{
		tx = e->mo.mx / (double)WIDTH * (e->xy.xmax - e->xy.xmin) + e->xy.xmin;
		ty = e->mo.my / (double)HEIGHT * (e->xy.ymax - e->xy.ymin) + e->xy.ymin;
		e->xy.xmin = tx - (tx - e->xy.xmin) * 0.8;
		e->xy.xmax = tx + (e->xy.xmax - tx) * 0.8; 
		e->xy.ymin = ty - (ty - e->xy.ymin) * 0.8;
		e->xy.ymax = ty + (e->xy.ymax - ty) * 0.8;
		printf("zoom out ++++ xmin : [%f] | xmax : [%f]\n\t\tymin : [%f] | ymax : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax);
		blackout(e);
		e->mo.m = 0;
	}
	if (e->k[E] == 1 ||  e->mo.m == 5)
	{
		tx = e->mo.mx / (double)WIDTH * (e->xy.xmax - e->xy.xmin) + e->xy.xmin;
		ty = e->mo.my / (double)WIDTH * (e->xy.xmax - e->xy.xmin) + e->xy.xmin;
		e->xy.xmin = tx - (tx - e->xy.xmin) / 0.8;
		e->xy.xmax = tx + (e->xy.xmax - tx) / 0.8; 
		e->xy.ymin = ty - (ty - e->xy.ymin) / 0.8;
		e->xy.ymax = ty + (e->xy.ymax - ty) / 0.8;
		printf("zoom in +++ xmin : [%f] | xmax : [%f]\n\t\tymin : [%f] | ymax : [%f]\n", e->xy.xmin, e->xy.xmax, e->xy.ymin, e->xy.ymax);
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
		e->xy.h = (e->xy.w * HEIGHT) / HEIGHT;
		e->xy.xmin = (e->fractol[0] == 'f' ? -2.182 : -e->xy.w / 2);
		e->xy.xmax = (e->fractol[0] == 'f' ? 2.6558 : e->xy.xmin + e->xy.w);
		e->xy.ymin = (e->fractol[0] == 'f' ? 0 : -e->xy.h / 2);
		e->xy.ymax = (e->fractol[0] == 'f' ? 9.9983 : e->xy.ymin + e->xy.h);
		blackout(e);
	}
	if (e->k[W] == 1)
	{
		printf("UP\n");	
		//	e->xy.ymin = e->xy.ymin - 0.005; 
		//	e->xy.ymax = e->xy.ymax + 0.005;
	}
	if (e->k[A] == 1)
	{
		printf("LEFT\n");	
		//	e->xy.xmin = e->xy.xmin - 0.005;
		//	e->xy.xmax = e->xy.xmax + 0.005;
	}
	if (e->k[S] == 1) 
	{
		printf("DOWN\n");	
		//	e->xy.ymin = e->xy.ymin - 0.005; 
		//	e->xy.ymax = e->xy.ymax + 0.005;
	}
	if (e->k[D] == 1)
	{
		printf("RIGHT\n");	
		//	e->xy.xmin = e->xy.xmin - 0.005;
		//	e->xy.xmax = e->xy.xmax + 0.005;
	}
	return (0);
}
