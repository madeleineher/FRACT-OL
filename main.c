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
		ft_putstr("\t./fractol julia | mandelbrot | fern | burn");
		ft_putstr(" | tricorn | koch | sierpinski\n");
	}
	if (i == 2)
	{
		ft_putendl("error:\tnot a valid fractal.\n");
		ft_putstr("./fractol julia | mandelbrot | fern | burn");
		ft_putstr(" | tricorn | koch | sierpinski\n");
	}
	if (i == 3)
		ft_putendl("error: mlx init error.");
	exit(0);
	return (0);
}

void		texting(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = 799;
	while (++i < HEIGHT)
	{
		while (++j < 1000)
			mlx_pixel_put(e->w.mp, e->w.wp, j, i, e->pal[e->c][4]);
		j = 799;
	}
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 50, 20, 0xFFFFFF, "FRACT'Ol");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 50, 100, 0xFFFFFF, e->fractol);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 180, 0xFFFFFF, "MOVE : W, A, S, D");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 210, 0xFFFFFF, "PAUSE : SPACEBAR");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 240, 0xFFFFFF, "ITERATE : I, U");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 270, 0xFFFFFF, "ZOOM : Q, E");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 300, 0xFFFFFF, "RESET : R");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 330, 0xFFFFFF, "EXIT : ESC");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 470, 0xFFFFFF, "ITERATIONS : ");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 500, 0xFFFFFF, ft_itoa(e->xy.nmax));
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 55, HEIGHT - 30, 0xFFFFFF, "MHERNAND");
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
			|| !(e->w.wp = mlx_new_window(e->w.mp, WIDTH + 200, HEIGHT, argv[1])))
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
