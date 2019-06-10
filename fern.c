/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:05:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/10 18:01:19 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		maps(t_env *e, int i)
{
	// return static_cast<int>((x_value - X_MIN) * X_DIM / (X_MAX - X_MIN));
	if (i == 1) // x
		return ((int)(e->f.x - X_MIN * WIDTH / (X_MAX - X_MIN)));
	else // y
		return ((int)(e->f.y - Y_MIN * HEIGHT / (Y_MAX - Y_MIN)));
	return (0);
}

void	drawpoint(t_env *e)
{
	if (e->f.x > 0 && e->f.x < 800 && e->f.y > 0 && e->f.y < 800)
		*(int *)&e->data[(int)e->f.x * (e->w.bpp / 8) + (int)e->f.y * e->w.sl] = 0xFFFFFF;
}

void	fernpoints(t_env *e)
{
	double	random;

	e->f.nx = 0;
	e->f.ny = 0;
	random  = (double)rand() / RAND_MAX;
	if (random < 0.1) // 1
	{ 
		printf("hello 1 ----> ");
		e->f.nx = 0.0;
		e->f.ny = 0.16 * e->f.y;
	}
	else if (random < 0.85) // 2
	{
		printf("hello 2 ====> ");
		e->f.nx =  0.85 * e->f.x + 0.04 * e->f.y;
		e->f.ny = -0.04 * e->f.x + 0.85 * e->f.y + 1.6;
	}
	else if (random < 0.93) // 3
	{
		printf("hello 3 ++++> ");
		e->f.nx =  0.2 * e->f.x + -0.26 * e->f.y;
		e->f.ny = 0.23 * e->f.x + 0.22  * e->f.y + 1.6;
	}
	else // 4
	{
		printf("hello 4 ~~~~> ");
		e->f.nx = -0.15 * e->f.x + 0.28 * e->f.y;
		e->f.ny =  0.26 * e->f.x + 0.24 * e->f.y + .44;
	}
	e->f.x = e->f.nx;
	e->f.y = e->f.ny;
	//printf("x : [%f] +++ y : [%f]\n", e->f.x, e->f.y);
}

void	fern(t_env *e)
{
	int		x;

	x = -1;
	while (++x < 1000000)
	{
		e->f.x = maps(e , 1);
		e->f.y = maps(e , 2);
		drawpoint(e);
		fernpoints(e);
		printf("x : [%d]\n", x);
	}
}
