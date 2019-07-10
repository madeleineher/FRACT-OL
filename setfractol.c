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

void 	juliasetup(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->j.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->j.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->xy.nmax = 100;
	e->j.tx = 0;
	e->j.ty = e->xy.ymin;
}

void	mandelsetup(t_env *e)
{
	e->m.x = -1;
	e->m.y = -1;
	e->m.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->m.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->m.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->xy.nmax = 100;
	e->m.tx = 0;
	e->m.ty = e->xy.ymin;
}

void	burnsetup(t_env *e)
{
	e->b.x = -1;
	e->b.y = -1;
	e->b.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->xy.nmax = 100;
	e->b.tx = 0;
	e->b.ty = e->xy.ymin;
}

void	tricornsetup(t_env *e)
{
	e->b.x = -1;
	e->b.y = -1;
	e->b.n = 0;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
	e->b.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	e->b.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	e->xy.nmax = 100;
	e->b.tx = 0;
	e->b.ty = e->xy.ymin;
}

void	kochsetup(t_env *e)
{
	e->o.kp[0].x = WIDTH / 5;
	e->o.kp[0].y = HEIGHT / 5;
	e->o.kp[1].x = WIDTH - WIDTH / 5;
	e->o.kp[1].y = HEIGHT / 5;
	e->o.kp[2].x = WIDTH - WIDTH / 5;
	e->o.kp[2].y = HEIGHT / 5;
	e->o.kp[3].x = WIDTH / 2;
	e->o.kp[3].y = HEIGHT - HEIGHT / 5;
	e->o.kp[4].x = WIDTH / 2;
	e->o.kp[4].y = HEIGHT - HEIGHT / 5;
	e->o.kp[5].x = WIDTH / 5;
	e->o.kp[5].y = WIDTH / 5;
 	e->o.iter = 5;
	e->xy.w = 5;
	e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
	e->xy.xmin = -e->xy.w / 2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
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
		e->xy.w = 5;
		e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
		e->xy.xmin = -2.182;
		e->xy.xmax = 2.6558;
		e->xy.ymin = 0;
		e->xy.ymax = 9.9983;
	}
	else if (ft_strcmp(e->fractol, "b") == 0)
		burnsetup(e);
	else if (ft_strcmp(e->fractol, "t") == 0)
		tricornsetup(e);
	else if (ft_strcmp(e->fractol, "k") == 0)
		kochsetup(e);
	e->xy.w_t = (e->xy.xmin + e->xy.xmax) / 2;
	e->xy.h_t = (e->xy.ymin + e->xy.ymax) / 2;
}
