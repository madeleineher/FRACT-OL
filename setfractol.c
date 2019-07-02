/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:04:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/02 16:14:23 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void 	juliasetup(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h/2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->j.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->j.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->j.tx = 0;
	e->j.ty = e->xy.ymin;
}

void	mandelsetup(t_env *e)
{
	e->m.i = -1;
	e->m.j = -1;
	e->m.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w/2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->m.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->m.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->m.tx = 0;
	e->m.ty = e->xy.ymin;
}

void	setfractol(t_env *e)
{
	e->xy.zoom = 1.0;
	if (ft_strcmp(e->fractol, "m") == 0)
		mandelsetup(e);
	else if (ft_strcmp(e->fractol, "j") == 0)
		juliasetup(e);
	else if (ft_strcmp(e->fractol, "f") == 0)
	{
		e->xy.xmin = -2.182;
		e->xy.xmax = 2.6558;
		e->xy.ymin = 0;
		e->xy.ymax = 9.9983;
	}
	e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
	e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
	/*else if (ft_strcmp(e->fractol, "k") == 0)
		kochsetup(e);
	else if (ft_strcmp(e->fractol, "s") == 0)
		sierpinskisetup(e);
	else if (ft_strcmp(e->fractol, "g") == 0)
		glynnsetup(e);*/
}
