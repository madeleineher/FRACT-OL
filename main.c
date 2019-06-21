/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 07:58:08 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 15:44:10 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int			error(int i)
{
	if (i == 1)
	{
		ft_putendl("usage: ./fractol FRACTAL_NAME/S");
		ft_putendl("       ./fractol julia | mandelbrot | fern");
	}
	if (i == 2)
	{
		ft_putendl("error: not a valid fractal.");
		ft_putendl("./fractol julia | mandelbrot | fern");
	}
	if (i == 3)
		ft_putendl("error: poor malloc.");
	exit(0);
	return (0);
}

void		texting(t_env *e)
{
	mlx_string_put(e->w.mp, e->w.wp, 30, 20, 0xFFFFFF, "HELLO");
}

int			check_fractols(char **args)
{
	if (ft_strcmp(args[1], "m") == 0) // mandelbrot
		return (0);
	else if (ft_strcmp(args[1], "j") == 0) // julia
		return (0); 
	else if (ft_strcmp(args[1], "k") == 0) //koch
		return (0);
	else if (ft_strcmp(args[1], "f") == 0) // fern
		return (0);
	else if (ft_strcmp(args[1], "s") == 0) // sierpinski
		return (0);
	else if (ft_strcmp(args[1], "g") == 0) // tree
		return (0);
	else if (ft_strcmp(args[1], "p") == 0) // sinking ship
		return (0);
	else
		return (-1);
}

int			main(int argc, char **argv)
{
	t_env	*e;

	e = NULL;
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		error(3);
	ft_bzero(e, sizeof(e));
	if (argc < 2)
		error(1);
	else if (check_fractols(argv) == -1)
		error(2);
	e->fractol = argv[1];
	if (!(e->w.mp = mlx_init())
			|| !(e->w.wp = mlx_new_window(e->w.mp, WIDTH, HEIGHT, argv[1])))
		error(3);
	if (!(e->w.ip = mlx_new_image(e->w.mp, WIDTH, HEIGHT)))
		error(3);
	if (!(e->data = mlx_get_data_addr(e->w.ip, &e->w.bpp, &e->w.sl, &e->w.end)))
		error(3);
	setfractol(e);
	color(e);
	start(e);
	mlx_loop(e->w.mp);
	return (0);
}
