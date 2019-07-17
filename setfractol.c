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
}

void	kochsetup(t_env *e)
{
	e->the = M_PI / 3;
	e->xy.xmin = WIDTH / 4;
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

void	frac_sierpinski(t_env *e)
{
	e->xy.xmin = 0;
	e->xy.xmax = WIDTH;
	e->xy.ymin = 0;
	e->xy.ymax = HEIGHT;
	e->s.ax = e->xy.xmax / 2;
	e->s.ay = e->xy.ymin;
	e->s.bx = e->xy.xmin;
	e->s.by = e->xy.ymax;
	e->s.cx = e->xy.xmax;
	e->s.cy = e->xy.ymax;
}

void	setfractol(t_env *e)
{
	e->xy.nmax = (e->fractol[0] == 'f' ? 1000000 : 10);
	if (ft_strcmp(e->fractol, "fern") == 0)
	{
		e->xy.w = 5;
		e->xy.h = (e->xy.w * HEIGHT) / WIDTH;
		e->xy.xmin = -2.182;
		e->xy.xmax = 2.6558;
		e->xy.ymin = 0;
		e->xy.ymax = 9.9983;
	}
	else if (ft_strcmp(e->fractol, "koch") == 0)
		kochsetup(e);
	else if (ft_strcmp(e->fractol, "sierpinski") == 0)
		frac_sierpinski(e);
	else
		frac_set(e);
	e->xy.w_t = (e->xy.xmax - e->xy.xmin);
	e->xy.h_t = (e->xy.ymax - e->xy.ymin);
}
