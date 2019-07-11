/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:04:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 15:18:46 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	frac_set(t_env *e)
{
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	if (ft_strcmp(e->fractol, "m") == 0)
	{
		e->m.n = 0;
		e->m.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
		e->m.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
		e->m.tx = 0;
		e->m.ty = e->xy.ymin;
	}
	else if (ft_strcmp(e->fractol, "j") == 0)
	{
		e->j.n = 0;
		e->j.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
		e->j.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
		e->j.tx = 0;
		e->j.ty = e->xy.ymin;
	}
}

void	frac_setwo(t_env *e)
{
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	if (ft_strcmp(e->fractol, "b") == 0)
	{
		e->b.n = 0;
		e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
		e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
		e->b.tx = 0;
		e->b.ty = e->xy.ymin;
	}
	else if (ft_strcmp(e->fractol, "t") == 0)
	{
		e->b.n = 0;
		e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
		e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
		e->b.tx = 0;
		e->b.ty = e->xy.ymin;
	}
}

void	kochsetup(t_env *e)
{
	e->the = M_PI / 3;
	e->xy.xmin = WIDTH /4;
	e->xy.xmax = WIDTH / 4 * 3;
	e->xy.ymin = HEIGHT / 4;
	e->xy.ymax = HEIGHT / 4 * 3;
	e->o.kp[0].x = e->xy.xmin;
	e->o.kp[0].y = e->xy.ymin;
	e->o.kp[1].x = e->xy.xmax;
	e->o.kp[1].y = e->xy.ymin;
	e->o.kp[2].x = e->xy.xmax;
	e->o.kp[2].y = e->xy.ymin;
	e->o.kp[3].x = e->xy.xmin * 2;
	e->o.kp[3].y = e->xy.ymax;
	e->o.kp[4].x = e->xy.xmin * 2;
	e->o.kp[4].y = e->xy.ymax;
	e->o.kp[5].x = e->xy.xmin;
	e->o.kp[5].y = e->xy.ymin;
	e->xy.nmax = 5;
}

void	setfractol(t_env *e)
{
	e->xy.nmax = (e->fractol[0] == 'f' ? 1000000 : 10);
	e->xy.zoom = 1.0;
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
		frac_set(e);
	else if (ft_strcmp(e->fractol, "julia") == 0)
		frac_set(e);
	else if (ft_strcmp(e->fractol, "fern") == 0)
	{
		e->xy.w = 5;
		e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
		e->xy.xmin = -2.182;
		e->xy.xmax = 2.6558;
		e->xy.ymin = 0;
		e->xy.ymax = 9.9983;
	}
	else if (ft_strcmp(e->fractol, "burning") == 0)
		frac_setwo(e);
	else if (ft_strcmp(e->fractol, "tricorn") == 0)
		frac_setwo(e);
	else if (ft_strcmp(e->fractol, "koch") == 0)
		kochsetup(e);
	else if (ft_strcmp(e->fractol, "double") == 0)
	{
		e->xy.w = 5;
		e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
		e->xy.xmin = -e->xy.w / 2;
		e->xy.xmax = e->xy.xmin + e->xy.w;
		e->xy.ymin = -e->xy.h / 2;
		e->xy.ymax = e->xy.ymin + e->xy.h;
		e->b.n = 0;
		e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
		e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
		e->b.tx = 0;
		e->b.ty = e->xy.ymin;
	}
}
