/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/17 13:59:18 by mhernand         ###   ########.fr       */
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

int		loop(t_env *e)
{
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 6, 1L << 6, mouse_move, e);
	mlx_hook(e->w.wp, 4, 1L << 4, mouse_click, e);
	mlx_hook(e->w.wp, 5, 1L << 5, mouse_no_click, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
	return (0);
}

int		start(t_env *e) // add number to fractal variable like DEFINES
{	
	if (ft_strcmp(e->fractol, "m") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->fractol, "j") == 0)
		julia(e);
	else if (ft_strcmp(e->fractol, "f") == 0)
		fern(e);
	else if (ft_strcmp(e->fractol, "k") == 0)
		koch(e);
	else if (ft_strcmp(e->fractol, "s") == 0)
		sierpinski(e);
	else if (ft_strcmp(e->fractol, "g") == 0)
		tree(e);
	loop(e);
	return (0);
}
