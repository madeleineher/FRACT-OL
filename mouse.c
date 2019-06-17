/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:19:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/17 16:46:32 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	blackout(t_env *e)
{
	int		i;
	int		j;
	int		c;

	j = -1;
	c = 0x000000;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			*(int *)&e->data[i * (e->w.bpp / 8) + j * e->w.sl] = c;
	}
//	printf("hello : x - [%d] | y - [%d]\n", e->mo.mx, e->mo.my);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	start(e);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		blackout(e);
		e->mo.mx = x;
		e->mo.my = y;
	}
	return (0);
}

int		mouse_click(int	button, int x, int y, t_env *e)
{
	e->mo.m = button;
	e->mo.mx = x;
	e->mo.my = y;
	return (0);
}

int		mouse_no_click(int button, int x, int y, t_env *e)
{
	e->mo.m = button;
	e->mo.mx = x;
	e->mo.my = y;
	return (0);
}
