/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:56:03 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 15:36:12 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void		line_setup(int x1, int y1, int x2, int y2, t_koh *tmp, t_env *e)
{
	tmp->x = x1;
	tmp->y = y1;
	e->n.dx = x2 - x1;
	e->n.dy = y2 - y1;
	e->n.ix = (e->n.dx > 0) ? 1 : -1;
	e->n.iy = (e->n.dy > 0) ? 1 : -1;
	e->n.dx = abs(e->n.dx);
	e->n.dy = abs(e->n.dy);
	if (tmp->x > 0 && tmp->x < WIDTH && tmp->y > 0 && tmp->y < HEIGHT)
		*(int *)&e->data[(int)tmp->x * (e->w.bpp / 8) + (int)tmp->y * e->w.sl] = 0xFFFFFF;
	e->n.tdx = e->n.dx / 2;
	e->n.tdy = e->n.dy / 2;
}

void		lines2(t_env *e, int i, t_koh tmp)
{
	while (++i < e->n.dy)
	{
		tmp.y += e->n.iy;
		e->n.tdy += e->n.dx;
		if (e->n.tdy >= e->n.dy)
		{
			e->n.tdy -= e->n.dy;
			tmp.x += e->n.ix;
		}
		if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
			*(int *)&e->data[(int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = 0xFFFFFF;
	}
}

void		lines(int x1, int y1, int x2, int y2, t_env *e)
{
	int		i;
	t_koh	tmp;

	i = -1;
	line_setup(x1, y1, x2, y2, &tmp, e);
	if (e->n.dx > e->n.dy)
	{
		while (++i < e->n.dx)
		{
			tmp.x += e->n.ix;
			e->n.tdx += e->n.dy;
			if (e->n.tdx >= e->n.dx)
			{
				e->n.tdx -= e->n.dx;
				tmp.y += e->n.iy;
			}
			if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
				*(int *)&e->data[(int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = 0xFFFFFF;
		}
	}
	else
		lines2(e, i, tmp);
}

void	kochangle(t_env *e, t_koh p1, t_koh p2, int rec)
{
	t_koh p3, p4, p5;
	double the = M_PI / 3;

	if (rec > 0)
	{
		p3 = (t_koh){(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
		p5 = (t_koh){(2 * p2.x + p1.x) / 3, (2 * p2.y + p1.y) / 3};
		p4 = (t_koh){p3.x + (p5.x - p3.x) * cos(the) + (p5.y - p3.y) * sin(the),
			p3.y - (p5.x - p3.x) * sin(the) + (p5.y - p3.y) * cos(the)};
		kochangle(e, p1, p3, rec - 1);
		kochangle(e, p3, p4, rec - 1);
		kochangle(e, p4, p5, rec - 1);
		kochangle(e, p5, p2, rec - 1);
	}
	else
		lines(p1.x, p1.y, p2.x, p2.y, e);

}

void	koch(t_env *e)
{
	t_koh k1, k2;
	t_koh k3, k4;
	t_koh k5, k6;
	int	r = 5;

	k1 = (t_koh){WIDTH / 5, HEIGHT / 5};
	k2 = (t_koh){WIDTH - WIDTH / 5, HEIGHT / 5};

	k3 = (t_koh){WIDTH - WIDTH / 5, HEIGHT / 5};
	k4 = (t_koh){WIDTH / 2, HEIGHT - HEIGHT / 5};

	k5 = (t_koh){WIDTH / 5, HEIGHT / 5};
	k6 = (t_koh){WIDTH / 2, HEIGHT - HEIGHT / 5};

	kochangle(e, k1, k2, r);
	kochangle(e, k3, k4, r);
	kochangle(e, k6, k5, r);
}
