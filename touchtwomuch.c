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
		e->xy.h_t = (e->k[W] ? (e->xy.ymax - e->xy.ymin) * 0.005 : \
			-(e->xy.ymax - e->xy.ymin) * 0.005);
		e->xy.ymin += e->xy.h_t;
		e->xy.ymax += e->xy.h_t;
		blackout(e);
	}
	if (e->k[A] == 1 || e->k[D] == 1)
	{
		e->xy.w_t = (e->k[A] ? (e->xy.xmax - e->xy.xmin) * 0.005 : \
			-(e->xy.xmax - e->xy.xmin) * 0.005);
		e->xy.xmin += e->xy.w_t;
		e->xy.xmax += e->xy.w_t;
		blackout(e);
	}
	return (0);
}

int		touchtwomuch(t_env *e)
{
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
	if (e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1 || e->k[D] == 1)
		movefractol(e);
	// if (e->k[N])
	// 	changefractol(e);
    return (0);
}