/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:56:03 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/09 12:50:38 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void		line_setup(int x1, int y1, int x2, int y2, t_kohp *tmp, t_env *e)
{
	tmp->x = x1;
	tmp->y = y1;
	e->o.n.dx = x2 - x1;
	e->o.n.dy = y2 - y1;
	e->o.n.ix = (e->o.n.dx > 0) ? 1 : -1;
	e->o.n.iy = (e->o.n.dy > 0) ? 1 : -1;
	e->o.n.dx = abs(e->o.n.dx);
	e->o.n.dy = abs(e->o.n.dy);
	if (tmp->x > 0 && tmp->x < WIDTH && tmp->y > 0 && tmp->y < HEIGHT)
		*(int *)&e->data[(int)tmp->x * (e->w.bpp / 8) + (int)tmp->y * \
			e->w.sl] = 0xFFFFFF;
	e->o.n.tdx = e->o.n.dx / 2;
	e->o.n.tdy = e->o.n.dy / 2;
}

void		lines2(t_env *e, int i, t_kohp tmp)
{
	while (++i < e->o.n.dy)
	{
		tmp.y += e->o.n.iy;
		e->o.n.tdy += e->o.n.dx;
		if (e->o.n.tdy >= e->o.n.dy)
		{
			e->o.n.tdy -= e->o.n.dy;
			tmp.x += e->o.n.ix;
		}
		if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
			*(int *)&e->data[(int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl]
				= 0xFFFFFF;
	}
}

void		lines(int x1, int y1, int x2, int y2, t_env *e)
{
	int		i;
	t_kohp	tmp;

	i = -1;
	line_setup(x1, y1, x2, y2, &tmp, e);
	if (e->o.n.dx > e->o.n.dy)
	{
		while (++i < e->o.n.dx)
		{
			tmp.x += e->o.n.ix;
			e->o.n.tdx += e->o.n.dy;
			if (e->o.n.tdx >= e->o.n.dx)
			{
				e->o.n.tdx -= e->o.n.dx;
				tmp.y += e->o.n.iy;
			}
			if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
				*(int *)&e->data[(int)tmp.x * (e->w.bpp / 8) + (int)tmp.y
					* e->w.sl] = 0xFFFFFF;
		}
	}
	else
		lines2(e, i, tmp);
}

void		kochangle(t_env *e, t_kohp p1, t_kohp p2, int rec)
{
	t_kohp	p3, p4, p5;
	double	the;

	the = M_PI / 3;
	if (rec > 0)
	{
		p3 = (t_kohp){(2 * p1.x + p2.x) / 3, (2 * p1.y + p2.y) / 3};
		p5 = (t_kohp){(2 * p2.x + p1.x) / 3, (2 * p2.y + p1.y) / 3};
		p4 = (t_kohp){p3.x + (p5.x - p3.x) * cos(the) + (p5.y - p3.y) * sin(the),
			p3.y - (p5.x - p3.x) * sin(the) + (p5.y - p3.y) * cos(the)};
		kochangle(e, p1, p3, rec - 1);
		kochangle(e, p3, p4, rec - 1);
		kochangle(e, p4, p5, rec - 1);
		kochangle(e, p5, p2, rec - 1);
	}
	else
		lines(p1.x, p1.y, p2.x, p2.y, e);
}

void		koch(t_env *e)
{
	kochangle(e, e->o.kp[0], e->o.kp[1], e->o.iter);
	kochangle(e, e->o.kp[2], e->o.kp[3], e->o.iter);
	kochangle(e, e->o.kp[4], e->o.kp[5], e->o.iter);
}