/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:18:23 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/17 09:18:47 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		key_press(int key, t_env *e)
{
	e->k[key] = 1;
	return (0);
}

int		key_release(int key, t_env *e)
{
	e->k[key] = 0;
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		e->mo.mx = x;
		e->mo.my = y;
	}
	printf("x == %d --- y == %d", e->mo.mx, e->mo.my);
	return (0);
}

int		mouse_click(int	button, int x, int y, t_env *e)
{
	e->mo.m = button;
	e->mo.mx = x;
	e->mo.my = y;
	printf("b : %d, x : %d, y : %d\n", e->mo.m, e->mo.mx, e->mo.my);
	return (0);
}

int		mouse_no_click(int button, int x, int y, t_env *e)
{
	e->mo.m = button;
	e->mo.mx = x;
	e->mo.my = y;
	return (0);
}
