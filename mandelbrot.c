/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 16:44:41 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	mandelcolor(t_env *e, t_man m)
{
	if (m.n == e->xy.nmax)
		*(int *)&e->data[m.x * (e->w.bpp / 8) + m.y * e->w.sl] = \
			e->pal[e->c][0];
	else
		*(int *)&e->data[m.x * (e->w.bpp / 8) + m.y * e->w.sl] = \
			e->pal[e->c][m.n % 5];
}

void	whilemandel(t_env *e, t_man *m) //, t_man *thr_man) // thr_man is a table .. read it by 4, cut horzontally.
{
	// Call start function to create threads, 
	//cut your tab depending your current thread and then this while loop 
	while (++m->n < e->xy.nmax) // decoupage avec ce variable nmax ..
	{
		m->two_a = m->a * m->a;
		m->two_b = m->b * m->b;
		m->two_ab = 2.0 * m->a * m->b;
		m->a = m->two_a - m->two_b + m->tx;
		m->b = m->two_ab + m->ty;
		if (m->a * m->a + m->b * m->b > 16.0)
			break ;
	}
}

void	mandelbrot(t_env *e, t_man m, int nth)
{ 
	// t_man	thr_man[WIDTH * HEIGHT];

	int start = nth * WIDTH / THREADS - 1;
	int end = start + WIDTH / THREADS;
	m.y = -1;
	m.ty = e->xy.ymin;
	m.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	m.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	while (++m.y < HEIGHT)
	{
		m.tx = e->xy.xmin + (e->xy.xmax - e->xy.xmin) * nth / THREADS;
		m.x = start;
		while (++m.x < end)
		{
			m.a = m.tx;
			m.b = m.ty;
			m.n = -1;
			whilemandel(e, &m);
			mandelcolor(e, m);
			m.tx += m.dx;
		}
		m.ty += m.dy;
	}
}
