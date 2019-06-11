/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fern.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:05:44 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/11 13:19:24 by mhernand         ###   ########.fr       */
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

void	drawpoint(int x, int y, t_env *e)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)&e->data[(int)x * (e->w.bpp / 8) + (int)y * e->w.sl] = 0xFFFFFF;
}

void	fernpoints(t_env *e)
{
	double	random;

	e->f.nx = 0;
	e->f.ny = 0;
	random  = (double)rand() / RAND_MAX;
	if (random < 0.01) // 1
	{ 
		printf("value 0 : [%f]\n", random);
		e->f.nx = 0.0;
		e->f.ny = 0.16 * e->f.y;
	}
	else if (random < 0.85) // 2
	{
		printf("value 1 : [%f]\n", random);
		e->f.nx =  0.85 * e->f.x + 0.04 * e->f.y;
		e->f.ny = -0.04 * e->f.x + 0.85 * e->f.y + 1.6;
	}
	else if (random < 0.93) // 3
	{
		printf("value 2: [%f]\n", random);
		e->f.nx =  0.2 * e->f.x + -0.26 * e->f.y;
		e->f.ny = 0.23 * e->f.x + 0.22  * e->f.y + 1.6;
	}
	else // 4
	{
		printf("value 3 : [%f]\n", random);
		e->f.nx = -0.15 * e->f.x + 0.28 * e->f.y;
		e->f.ny =  0.26 * e->f.x + 0.24 * e->f.y + .44;
	}
	e->f.x = e->f.nx;
	e->f.y = e->f.ny;
}

void	fern(t_env *e)
{
	int		x;

	x = -1;
	while (++x < 1000000)
	{
		fernpoints(e);
		//e->f.x = (int)(e->f.x - X_MIN * WIDTH / (X_MAX - X_MIN));
		//e->f.y = (int)(e->f.y - Y_MIN * HEIGHT / (Y_MAX - Y_MIN));
		drawpoint((int)(e->f.x - X_MIN * WIDTH / (X_MAX - X_MIN)), (int)(e->f.y - Y_MIN * HEIGHT / (Y_MAX - Y_MIN)), e);
	}
}
