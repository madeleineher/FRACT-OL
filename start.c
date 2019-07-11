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
	t_man	m = th->env->m;
	t_jul	j = th->env->j;
	t_fer	f = th->env->f;
	t_burn	b = th->env->b;
	t_tri	t = th->env->t;
	// t_koh	h = th->env->h;
	// t_sie	s = th->env->s;
	if (ft_strcmp(th->env->fractol, "mandelbrot") == 0)
		mandelbrot(th->env, m);
	else if (ft_strcmp(th->env->fractol, "fern") == 0)
		fern(th->env, f);
	else if (ft_strcmp(th->env->fractol, "burning") == 0)
		burn(th->env, b);
	else if (ft_strcmp(th->env->fractol, "julia") == 0)
		julia(th->env, j);
	else if (ft_strcmp(th->env->fractol, "tricorn") == 0)
		tricorn(th->env, t);
	else if (ft_strcmp(th->env->fractol, "koch") == 0)
		koch(th->env);
	else if (ft_strcmp(th->env->fractol, "sierpinski") == 0)
		sierpinski(th->env);
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
		// starth = th[i] * WIDHT / THREADS - 1;
		// endth = xstart + WIDTH / THREADS;
		pthread_create(&thread[i], NULL, fractols, &th[i]);
	}
	i = -1;
	while (++i < THREADS)
		pthread_join(thread[i], NULL);
	loop(e);
}
