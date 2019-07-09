/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:12:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/03 16:39:17 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	juliacolor(t_env *e, t_jul j)
{
	if (j.n == e->xy.nmax)
		*(int *)&e->data[j.x * (e->w.bpp / 8) + j.y * e->w.sl]
			= e->pal[e->c][0];
	else
		*(int *)&e->data[j.x * (e->w.bpp / 8) + j.y * e->w.sl]
			= e->pal[e->c][j.n % 5];
}

// float	map(int m)
// {
// 	return (-1 + (1 - -1) * ((m - 0) / (float)((WIDTH - 0))));
// }

void	map(t_env *e)
{
	e->xy.mre = ((double)e->mo.mx / (WIDTH / (e->xy.xmax - e->xy.xmin))
			+ e->xy.xmin);
	e->xy.mri = ((double)e->mo.my / (HEIGHT / (e->xy.ymax - e->xy.ymin))
			+ e->xy.ymin);
}

void	whilejulia(t_env *e, t_jul *j)
{
	while (++j->n < e->xy.nmax)
	{
		j->two_a = j->a * j->a;
		j->two_b = j->b * j->b;
		j->two_ab = 2.0 * j->a * j->b;
		map(e);
		j->a = j->two_a - j->two_b + e->xy.mre;
		j->b = j->two_ab + e->xy.mri; 
		if (j->a * j->a + j->b * j->b > 16.0)
			break;
	}
}

void	julia(t_env *e, t_jul j)
{
	j.y = -1;
	j.ty = e->xy.ymin;
	j.dx = (e->xy.xmax - e->xy.xmin) / (WIDTH);
	j.dy = (e->xy.ymax - e->xy.ymin) / (HEIGHT);
	while (++j.y < HEIGHT)
	{
		j.tx = e->xy.xmin;
		j.x = -1;
		while (++j.x < WIDTH)
		{
			j.a = j.tx;
			j.b = j.ty;
			j.n = -1;
			whilejulia(e, &j);
			juliacolor(e, j);
			j.tx += j.dx;
		}
		j.ty += j.dy;
	}
}
