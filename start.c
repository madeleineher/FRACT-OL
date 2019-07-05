/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 16:51:09 by mhernand         ###   ########.fr       */
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
	texting(e);
	mlx_hook(e->w.wp, 2, 1L << 2, key_press, e);
	mlx_hook(e->w.wp, 3, 1L << 3, key_release, e);
	mlx_hook(e->w.wp, 6, 1L << 6, mouse_move, e);
	mlx_hook(e->w.wp, 4, 1L << 4, mouse_click, e);
	mlx_hook(e->w.wp, 5, 1L << 5, mouse_no_click, e);
	mlx_hook(e->w.wp, 17, 1L << 17, quit, e);
	mlx_loop_hook(e->w.mp, touch, e);
	return (0);
}

void	*fractols(void *pscreen) // add number to fractal variable like DEFINES
{
	t_thr	*th;

	th = (t_thr *)pscreen; 
	printf("test %f\n", th->env->m.ty);
	t_man m = th->env->m;
	if (ft_strcmp(th->env->fractol, "m") == 0) // !! attention to structure call !
		mandelbrot(th->env, m);
	printf("sortie test %f\n", th->env->m.ty);
/*	else if (ft_strcmp(e->fractol, "j") == 0)
		julia(e);
	else if (ft_strcmp(e->fractol, "f") == 0)
		fern(e);
	else if (ft_strcmp(e->fractol, "k") == 0)
		koch(e);
	else if (ft_strcmp(e->fractol, "s") == 0)
		sierpinski(e);
	else if (ft_strcmp(e->fractol, "b") == 0)
		burn(e);
		*/
	pthread_exit(NULL);
}

void	start(t_env *e)
{
	int			i;
	pthread_t	thread[THREADS];
	t_thr		th[THREADS];

	i = -1;
	while (++i < THREADS)
	{
		th[i].env = e;
		th[i].nth = i;
		pthread_create(&thread[i], NULL, fractols, &th[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(thread[i], NULL);

	loop(e);
}
