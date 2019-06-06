/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/06 18:32:22 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		quit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

int		key_press(int key, t_env *e)
{
	e->k[key] = 1;
	return (0);
}

int		key_release(int key, t_env *e)
{
	e->k[key] = 0;
	return (0);
}

void	loop(t_env *e)
{
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
}

void	start(t_env *e)
{	
	if (ft_strcmp(e->fractol, "Mandelbrot") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->fractol, "Julia") == 0)
		julia(e);
	//else if (ft_strcmp(e->fractol, "Koch") == 0)
	//	koch(e);
	//else if (ft_strcmp(e->fractol, "Fern") == 0)
	//	fern(e);
	//else if (ft_strcmp(e->fractol, "Sierpinski") == 0)
	//	sierpinski(e);
	//else if (ft_strcmp(e->fractol, "Tree") == 0)
	//	tree(e);
	loop(e);
}
