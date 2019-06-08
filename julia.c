/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:14:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/08 18:43:17 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	juliasetup(t_env *e)
{
	e->j.x = -1;
	e->j.y = -1;
	e->j.nmax = 1000;
	e->j.n = -1;
}

void	juliacolor(t_env *e)
{
	if (e->j.n == e->j.nmax)
	{
		*(int *)&e->data[e->j.x * (e->w.bpp / 8) + e->j.y * e->w.sl]
			= 0x0000FF; //map(e);
		printf("hello\n");
	}
		*(int *)&e->data[e->j.x + 350 * (e->w.bpp / 8) + e->j.y + 350 * e->w.sl]
			= e->j.n * 0xFFFFFF; //map(e);
}

void	julia(t_env *e)
{
	double	zx = -2.5;
	double	zy = -1;
	double	xtemp = 0;
	double	cy = 0;
	double	cx = 0;
	double	zy_const = 2;
	double	zx_const = 3;

 	cy = -0.8; // these c values need to be constants
 	cx = 0.156;
	juliasetup(e);
	while (++e->j.y < HEIGHT)
	{
		zy =  ((double)e->j.y / HEIGHT * zy_const - 1.0);
		e->j.x = -1;
		while (++e->j.x < WIDTH)
		{
			zx = ((double)e->j.x / WIDTH * zx_const - 2.5);
			e->j.n = -1;
 			while (++e->j.n < e->j.nmax && zx * zx + zy * zy <= 4)
			{
				xtemp = zx * zx - zy * zy;
				zy = 2 * zx * zy + cy;
				zx = xtemp + cx;
			}
			//printf("value : [%f]\n", zx * zx + zy * zy);
			//printf("[%d]\n", e->j.n);
			juliacolor(e);
		}
	}
}
