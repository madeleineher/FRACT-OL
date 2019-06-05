/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/05 16:22:01 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_env *e)
{
	int		n = 0;
	int		n_max = 100;
	float	w = 5;
	float	h = (w * HEIGHT) / WIDTH;

	float	xmin = -w/2;
	float	ymin = -h/2;

	float	xmax = xmin + w;
	float	ymax = ymin + h;

	float	dx = (xmax - xmin) / (WIDTH);
	float	dy = (ymax - ymin) / (HEIGHT);

	float	y = ymin;
	float	x = 0;
	int		i = 0;
	int		j = 0;
	for (i = 0; i < HEIGHT; i++)
	{
		x = xmin;
		for (j = 0; j < WIDTH; j++)
		{
			float a = x;
			float b = y;
			n = -1;
			while (++n < n_max)
			{
				float aa = a * a;
				float bb = b * b;
				float twoab = 2.0 * a * b;
				a = aa - bb + x;
				b = twoab + y;
				if (a*a + b*b > 16.0)
					break;
			}
			if (n == n_max)
			{
				//*(int *)&e->data[i * (e->w.bpp / 8) + j * e->w.sl] = 0x00FF00;
				mlx_pixel_put(e->w.mp, e->w.wp, j, i, 0xFFFFFF);
				printf("hi\n");
			}
			else
			{
				//*(int *)&e->data[i * (e->w.bpp / 8) + j * e->w.sl] = 0xFF0000;
				mlx_pixel_put(e->w.mp, e->w.wp, j, i, 0x000000);
				printf("hello\n");
			}
			x += dx;
		}
		y += dy;
	}	
}

void	start(t_env *e)
{	
	if (ft_strcmp(e->fractol, "Manelbrot") != 0)
		mandelbrot(e);
}
