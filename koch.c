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

void		line_setup(t_kohp t1_t2[2], t_kohp *tmp, t_env *e)
{
	tmp->x = t1_t2[0].x;
	tmp->y = t1_t2[0].y;
	e->o.n.dx = t1_t2[1].x - t1_t2[0].x;
	e->o.n.dy = t1_t2[1].y - t1_t2[0].y;
	e->o.n.ix = (e->o.n.dx > 0) ? 1 : -1;
	e->o.n.iy = (e->o.n.dy > 0) ? 1 : -1;
	e->o.n.dx = abs(e->o.n.dx);
	e->o.n.dy = abs(e->o.n.dy);
	if (tmp->x > 0 && tmp->x < WIDTH && tmp->y > 0 && tmp->y < HEIGHT)
		colorkoch(e, *tmp, 0);
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
			colorkoch(e, tmp, i);
	}
}

void		lines(t_kohp t1, t_kohp t2, t_env *e)
{
	t_kohp	tmp;
	t_kohp	t1_t2[2];

	t1_t2[0] = t1;
	t1_t2[1] = t2;
	e->o.n.i = -1;
	line_setup(t1_t2, &tmp, e);
	if (e->o.n.dx > e->o.n.dy)
	{
		while (++e->o.n.i < e->o.n.dx)
		{
			tmp.x += e->o.n.ix;
			e->o.n.tdx += e->o.n.dy;
			if (e->o.n.tdx >= e->o.n.dx)
			{
				e->o.n.tdx -= e->o.n.dx;
				tmp.y += e->o.n.iy;
			}
			if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
				colorkoch(e, tmp, e->o.n.i);
		}
	}
	else
		lines2(e, e->o.n.i, tmp);
}

void		kochangle(t_env *e, t_kohp t[2], int rec)
{
	t_kohp	p3[3];
	t_kohp	tmp[2];

	if (rec > 0)
	{
		p3[0] = (t_kohp){(2 * t[0].x + t[1].x) / 3, (2 * t[0].y + t[1].y) / 3};
		p3[2] = (t_kohp){(2 * t[1].x + t[0].x) / 3, (2 * t[1].y + t[0].y) / 3};
		p3[1] = (t_kohp){p3[0].x + (p3[2].x - p3[0].x) * cos(e->the) + \
			(p3[2].y - p3[0].y) * sin(e->the), p3[0].y - (p3[2].x - \
			p3[0].x) * sin(e->the) + (p3[2].y - p3[0].y) * cos(e->the)};
		tmp[0] = t[0];
		tmp[1] = p3[0];
		kochangle(e, tmp, rec - 1);
		tmp[0] = p3[0];
		tmp[1] = p3[1];
		kochangle(e, tmp, rec - 1);
		tmp[0] = p3[1];
		tmp[1] = p3[2];
		kochangle(e, tmp, rec - 1);
		tmp[0] = p3[2];
		tmp[1] = t[1];
		kochangle(e, tmp, rec - 1);
	}
	else
		lines(t[0], t[1], e);
}

void		koch(t_env *e)
{
	t_kohp tab1[2];
	t_kohp tab2[2];
	t_kohp tab3[2];

	e->o.kp[0].x = e->xy.xmin;
	e->o.kp[0].y = e->xy.ymin;
	e->o.kp[1].x = e->xy.xmax;
	e->o.kp[1].y = e->xy.ymin;
	e->o.kp[2].x = e->xy.xmax;
	e->o.kp[2].y = e->xy.ymin;
	e->o.kp[3].x = e->xy.xmin * 2;
	e->o.kp[3].y = e->xy.ymax;
	e->o.kp[4].x = e->xy.xmin * 2;
	e->o.kp[4].y = e->xy.ymax;
	e->o.kp[5].x = e->xy.xmin;
	e->o.kp[5].y = e->xy.ymin;
	tab1[0] = e->o.kp[0];
	tab1[1] = e->o.kp[1];
	tab2[0] = e->o.kp[2];
	tab2[1] = e->o.kp[3];
	tab3[0] = e->o.kp[4];
	tab3[1] = e->o.kp[5];
	kochangle(e, tab1, e->xy.nmax);
	kochangle(e, tab2, e->xy.nmax);
	kochangle(e, tab3, e->xy.nmax);
}
