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
	if (e->oldfrac != e->fractol || e->xy.oldmax != e->xy.nmax)
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

// void	*fractols(void *pscreen) // add number to fractal variable like DEFINES
void	start(t_env *e) // add number to fractal variable like DEFINES
{
	// t_thr	*th;

	// th = (t_thr *)pscreen; 
	// t_man	m = th->env->m;
	// t_jul	j = th->env->j;
	// t_fer	f = th->env->f;
	// t_burn	b = th->env->b;
	// t_tri	t = th->env->t;
	// t_koch	o = th->env->o;
	// t_dou	d = th->env->d;
	// t_sie	s = th->env->s;
	if (ft_strcmp(e->fractol, "mandelbrot") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->fractol, "fern") == 0)
		fern(e);
	if (ft_strcmp(e->fractol, "burning") == 0)
		burn(e);
	else if (ft_strcmp(e->fractol, "tricorn") == 0)
		tricorn(e);
	else if (ft_strcmp(e->fractol, "doubleburning") == 0)
		doubleburn(e);
	else if (ft_strcmp(e->fractol, "sierpinski") == 0)
		sierpinski(e);
	else if (ft_strcmp(e->fractol, "julia") == 0)
		julia(e);
	else if (ft_strcmp(e->fractol, "glynn") == 0)
		glynn(e);
	// else if (ft_strcmp(th->env->fractol, "koch") == 0)
	// 	koch(th->env, o);

	// keep thread thing ....
	// else if (ft_strcmp(th->env->fractol, "koch") == 0)
	// 	koch(th->env, o);
	// pthread_exit(NULL);
 	loop(e);

}

// void	start(t_env *e)
// {
// 	int			i;
// 	pthread_t	thread[THREADS];
// 	t_thr		th[THREADS];

// 	i = -1;
// 	while (++i < THREADS)
// 	{
// 		th[i].env = e;
// 		th[i].nth = i;
// 		pthread_create(&thread[i], NULL, fractols, &th[i]);
// 	}
// 	i = -1;
// 	while (++i < THREADS)
// 		pthread_join(thread[i], NULL);
// 	loop(e);
// }
