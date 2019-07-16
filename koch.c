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

void		line_setup(t_kohp t1_t2[2], t_kohp *tmp, t_koch *o, t_env *e)
{
	tmp->x = t1_t2[0].x;
	tmp->y = t1_t2[0].y;
	o->n.dx = t1_t2[1].x - t1_t2[0].x;
	o->n.dy = t1_t2[1].y - t1_t2[0].y;
	o->n.ix = (o->n.dx > 0) ? 1 : -1;
	o->n.iy = (o->n.dy > 0) ? 1 : -1;
	o->n.dx = abs(o->n.dx);
	o->n.dy = abs(o->n.dy);
	if (tmp->x > 0 && tmp->x < WIDTH && tmp->y > 0 && tmp->y < HEIGHT)
		colorkoch(e, *tmp);
	o->n.tdx = o->n.dx / 2;
	o->n.tdy = o->n.dy / 2;
}

void		lines2(t_env *e, int i, t_kohp tmp, t_koch *o)
{
	while (++i < o->n.dy)
	{
		tmp.y += o->n.iy;
		o->n.tdy += o->n.dx;
		if (o->n.tdy >= o->n.dy)
		{
			o->n.tdy -= o->n.dy;
			tmp.x += o->n.ix;
		}
		if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
			colorkoch(e, tmp);
	}
}

void		lines(t_kohp t1, t_kohp t2, t_env *e, t_koch *o)
{
	t_kohp	tmp;
	t_kohp	t1_t2[2];

	t1_t2[0] = t1;
	t1_t2[1] = t2;
	o->n.i = -1;
	line_setup(t1_t2, &tmp, o, e);
	if (o->n.dx > o->n.dy)
	{
		while (++o->n.i < o->n.dx)
		{
			tmp.x += o->n.ix;
			o->n.tdx += o->n.dy;
			if (o->n.tdx >= o->n.dx)
			{
				o->n.tdx -= o->n.dx;
				tmp.y += o->n.iy;
			}
			if (tmp.x > 0 && tmp.x < WIDTH && tmp.y > 0 && tmp.y < HEIGHT)
				colorkoch(e, tmp);
		}
	}
	else
		lines2(e, o->n.i, tmp, o);
}

void		kochangle(t_env *e, t_kohp t[2], int rec, t_koch o)
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
		kochangle(e, tmp, rec - 1, o);
		tmp[0] = p3[0];
		tmp[1] = p3[1];
		kochangle(e, tmp, rec - 1, o);
		tmp[0] = p3[1];
		tmp[1] = p3[2];
		kochangle(e, tmp, rec - 1, o);
		tmp[0] = p3[2];
		tmp[1] = t[1];
		kochangle(e, tmp, rec - 1, o);
	}
	else
		lines(t[0], t[1], e, &o);
}

void		koch(t_env *e, t_koch o)
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
	tab1[0] = o.kp[0];
	tab1[1] = o.kp[1];
	tab2[0] = o.kp[2];
	tab2[1] = o.kp[3];
	tab3[0] = o.kp[4];
	tab3[1] = o.kp[5];
	kochangle(e, tab1, e->xy.nmax, o);
	kochangle(e, tab2, e->xy.nmax, o);
	kochangle(e, tab3, e->xy.nmax, o);
}
