/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:04:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 15:23:13 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void 	juliasetup(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.n = 0;
	e->j.nmax = 100;
	e->j.w = 5;
	e->j.h = (e->j.w * HEIGHT) / WIDTH;
	e->j.xmin = -e->j.w/2;
	e->j.xmax = e->j.xmin + e->j.w;
	e->j.ymin = -e->j.h/2;
	e->j.ymax = e->j.ymin + e->j.h;
	e->j.dx = (e->j.xmax - e->j.xmin) / (WIDTH);
	e->j.dy = (e->j.ymax - e->j.ymin) / (HEIGHT);
	e->j.tx = 0;
	e->j.ty = e->j.ymin;
}

void	mandelsetup(t_env *e)
{
	e->m.i = -1;
	e->m.j = -1;
	e->m.n = 0;
	e->m.nmax = 1000;
	e->m.w = 5;
	e->m.h = (e->m.w * HEIGHT) / WIDTH;
	e->m.xmin = -e->m.w/2;
	e->m.xmax = e->m.xmin + e->m.w;
	e->m.ymin = -e->m.h/2;
	e->m.ymax = e->m.ymin + e->m.h;
	e->m.dx = (e->m.xmax - e->m.xmin) / (WIDTH);
	e->m.dy = (e->m.ymax - e->m.ymin) / (HEIGHT);
	e->m.tx = 0;
	e->m.ty = e->m.ymin;
}

void	fernsetup(t_env *e)
{
	e->f.x_min = -2.182;
	e->f.x_max = 2.6558;
	e->f.y_min = 0;
	e->f.y_max = 9.9983;
}

void	setfractol(t_env *e)
{
	if (ft_strcmp(e->fractol, "m") == 0)
		mandelsetup(e);
	else if (ft_strcmp(e->fractol, "j") == 0)
		juliasetup(e);
	else if (ft_strcmp(e->fractol, "f") == 0)
		fernsetup(e);
	/*else if (ft_strcmp(e->fractol, "k") == 0)
		kochsetup(e);
	else if (ft_strcmp(e->fractol, "s") == 0)
		sierpinskisetup(e);
	else if (ft_strcmp(e->fractol, "g") == 0)
		glynnsetup(e);*/
}
