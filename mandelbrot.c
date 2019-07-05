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
		*(int *)&e->data[m.x * (e->w.bpp / 8) + m.y * e->w.sl] 
			= e->pal[e->c][0];
	else
		*(int *)&e->data[m.x * (e->w.bpp / 8) + m.y * e->w.sl]
			= e->pal[e->c][m.n % 5];
}

void	mandelbrot(t_env *e, t_man m)
{
	m.y = -1;
	m.ty = e->xy.ymin;
	m.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	m.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	while (++m.y < HEIGHT)
	{
		m.tx = e->xy.xmin;
		m.x = -1;
		while (++m.x < WIDTH)
		{
			m.a = m.tx;
			m.b = m.ty;
			m.n = -1;
			while (++m.n < e->xy.nmax)
			{
				m.two_a = m.a * m.a;
				m.two_b = m.b * m.b;
				m.two_ab = 2.0 * m.a * m.b;
				m.a = m.two_a - m.two_b + m.tx;
				m.b = m.two_ab + m.ty;
				if (m.a * m.a + m.b * m.b > 16.0)
					break;
			}
			mandelcolor(e, m);
			m.tx += m.dx;
		}
		m.ty += m.dy;
	}
}
