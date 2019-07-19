/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 07:58:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 14:58:40 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int			error(int i)
{
	if (i == 1)
	{
		ft_putendl("usage:\t./fractol FRACTAL_NAME");
		ft_putstr("\t./fractol julia | mandelbrot | fern | burning");
		ft_putstr(" | tricorn | koch | sierpinski | doubleburning | glynn\n");
	}
	if (i == 2)
	{
		ft_putendl("error:\tnot a valid fractal.\n");
		ft_putstr("./fractol julia | mandelbrot | fern | burning");
		ft_putstr(" | tricorn | koch | sierpinski | doubleburning | glynn\n");
	}
	if (i == 3)
		ft_putendl("error: mlx init error.");
	exit(0);
	return (0);
}

int			check_fractols(char **args)
{
	if (ft_strcmp(args[1], "mandelbrot") == 0)
		return (0);
	else if (ft_strcmp(args[1], "julia") == 0)
		return (0);
	else if (ft_strcmp(args[1], "koch") == 0)
		return (0);
	else if (ft_strcmp(args[1], "fern") == 0)
		return (0);
	else if (ft_strcmp(args[1], "burning") == 0)
		return (0);
	else if (ft_strcmp(args[1], "tricorn") == 0)
		return (0);
	else if (ft_strcmp(args[1], "sierpinski") == 0)
		return (0);
	else if (ft_strcmp(args[1], "doubleburning") == 0)
		return (0);
	else if (ft_strcmp(args[1], "glynn") == 0)
		return (0);
	else
		return (-1);
}

int			main(int argc, char **argv)
{
	t_env	e;

	// e = NULL;
	// if (!(e = (t_env*)malloc(sizeof(t_env))))
	// 	error(3);
	ft_bzero(&e, sizeof(e));
	if (argc != 2)
		error(1);
	else if (check_fractols(argv) == -1)
		error(2);
	e.fractol = argv[1];
	if (!(e.w.mp = mlx_init()) \
		|| !(e.w.wp = mlx_new_window(e.w.mp, WIDTH + 200, HEIGHT, \
		"FRACT'OL")))
		error(3);
	if (!(e.w.ip = mlx_new_image(e.w.mp, WIDTH, HEIGHT)))
		error(3);
	if (!(e.data = mlx_get_data_addr(e.w.ip, &e.w.bpp, &e.w.sl, &e.w.end)))
		error(3);
	setfractol(&e);
	color(&e);
	start(&e);
	mlx_loop(e.w.mp);
	return (0);
}
