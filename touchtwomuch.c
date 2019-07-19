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

void		movefractol(t_env *e)
{
	if (e->k[W] == 1 || e->k[S] == 1)
	{
		e->xy.ymin += (e->k[W] ? 0.009 : -0.009);
		e->xy.ymax += (e->k[W] ? 0.009 : -0.009);
		if (e->fractol[0] == 'k' || e->fractol[0] == 's')
		{
			e->xy.ymin += (e->k[W] ? 2.5 : -2.5);
			e->xy.ymax += (e->k[W] ? 2.5 : -2.5);
		}
		e->k[W] = 0;
		e->k[S] = 0;
	}
	if (e->k[A] == 1 || e->k[D] == 1)
	{
		e->xy.xmin += (e->k[A] ? 0.009 : -0.009);
		e->xy.xmax += (e->k[A] ? 0.009 : -0.009);
		if (e->fractol[0] == 'k' || e->fractol[0] == 's')
		{
			e->xy.xmin += (e->k[A] ? 2.5 : -2.5);
			e->xy.xmax += (e->k[A] ? 2.5 : -2.5);
		}
		e->k[A] = 0;
		e->k[D] = 0;
	}
	blackout(e);
}

int			changefractol(t_env *e)
{
	int		i;
	char	*fractols[9];

	i = -1;
	fractols[0] = "julia";
	fractols[1] = "mandelbrot";
	fractols[2] = "fern";
	fractols[3] = "burning";
	fractols[4] = "tricorn";
	fractols[5] = "koch";
	fractols[6] = "sierpinski";
	fractols[7] = "doubleburning";
	fractols[8] = "glynn";
	e->oldfrac = e->fractol;
	while (fractols[++i][0] != e->fractol[0])
		;
	if (i < 8)
		i++;
	else
		i = 0;
	e->fractol = fractols[i];
	e->k[N] = 0;
	setfractol(e);
	blackout(e);
	return (0);
}

int			changecolor(t_env *e)
{
	if (e->k[Z] == 1)
		e->clr.ph1_r += (e->clr.ph1_r >= 0 && e->clr.ph1_r < 5 ? 2 : 0);
	if (e->k[X] == 1)
		e->clr.ph2_g += (e->clr.ph2_g >= 0 && e->clr.ph2_g < 5 ? 2 : 0);
	if (e->k[C] == 1)
		e->clr.ph3_b += (e->clr.ph3_b >= 0 && e->clr.ph3_b < 5 ? 2 : 0);
	e->clr.ph1_r = (e->clr.ph1_r == 6 ? 0 : e->clr.ph1_r);
	e->clr.ph2_g = (e->clr.ph2_g == 6 ? 0 : e->clr.ph2_g);
	e->clr.ph3_b = (e->clr.ph3_b == 6 ? 0 : e->clr.ph3_b);
	e->k[Z] = 0;
	e->k[X] = 0;
	e->k[C] = 0;
	color(e);
	texting(e);
	blackout(e);
	return (0);
}

int			changecolorfreq(t_env *e)
{
	if (e->k[V] == 1)
		e->clr.fq1 += (.001 * e->clr.neg);
	if (e->k[G] == 1)
		e->clr.fq2 += (.001 * e->clr.neg);
	if (e->k[B] == 1)
		e->clr.fq3 += (.001 * e->clr.neg);
	e->k[V] = 0;
	e->k[G] = 0;
	e->k[B] = 0;
	color(e);
	blackout(e);
	return (0);
}

int			touchtwomuch(t_env *e)
{
	if (e->k[R] == 1)
	{
		setfractol(e);
		e->clr.amp = 127;
		e->clr.ph1_r = 0;
		e->clr.ph2_g = 4;
		e->clr.ph3_b = 2;
		e->k[R] = 0;
		color(e);
		blackout(e);
	}
	if (e->k[W] == 1 || e->k[S] == 1 || e->k[A] == 1 || e->k[D] == 1)
		movefractol(e);
	if (e->k[N] == 1)
		changefractol(e);
	if (e->k[Z] == 1 || e->k[X] == 1 || e->k[C] == 1)
		changecolor(e);
	if (e->k[V] == 1 || e->k[B] == 1 || e->k[G] == 1)
		changecolorfreq(e);
	return (0);
}
