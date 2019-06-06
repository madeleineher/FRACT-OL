/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/06 10:54:53 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelsetup(t_env *e)
{
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

void	mandelbrot(t_env *e)
{
	int		i = -1;
	int		j = 0;
	while (++i < HEIGHT)
	{
		e->m.tx = e->m.xmin;
		while (++j < WIDTH)
		{
			e->m.a = e->m.tx;
			e->m.b = e->m.ty;
			e->m.n = -1;
			while (++e->m.n < e->m.nmax)
			{
				e->m.two_a = e->m.a * e->m.a;
				e->m.two_b = e->m.b * e->m.b;
				e->m.two_ab = 2.0 * e->m.a * e->m.b;
				e->m.a = e->m.two_a - e->m.two_b + e->m.tx;
				e->m.b = e->m.two_ab + e->m.ty;
				if (e->m.a * e->m.a + e->m.b * e->m.b > 16.0)
					break;
			}
			if (e->m.n == e->m.nmax)
				*(int *)&e->data[j * (e->w.bpp / 8) + i * e->w.sl] = 0x00FF00;
			else
				*(int *)&e->data[j * (e->w.bpp / 8) + i * e->w.sl] = 0xFF0000;
			e->m.tx += e->m.dx;
		}
		j = -1;
		e->m.ty += e->m.dy;
	}	
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
}

void	start(t_env *e)
{	
	if (ft_strcmp(e->fractol, "Manelbrot") != 0)
	{
		mandelsetup(e);
		mandelbrot(e);
	}
}
