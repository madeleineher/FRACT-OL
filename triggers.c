/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 09:19:10 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 16:12:49 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		key_press(int key, t_env *e)
{
	if (key == KEY_SPACEBAR)
		e->k[KEY_SPACEBAR] = (e->k[KEY_SPACEBAR] == 1 ? 0 : 1);
	if (key == H)
		e->k[H] = (e->k[H] == 1 ? 0 : 1);
	else
		e->k[key] = 1;
	return (0);
}

int		key_release(int key, t_env *e)
{
	if (key == KEY_SPACEBAR)
		return (0);
	if (key == H)
		return (0);
	else
		e->k[key] = 0;
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT
		&& e->fractol[0] == 'j' && e->k[KEY_SPACEBAR] != 1)
	{
		e->mo.mx = x;
		e->mo.my = y;
		blackout(e);
	}
	return (0);
}

int		mouse_click(int button, int x, int y, t_env *e)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		e->mo.m = button;
		e->mo.mx = x;
		e->mo.my = y;
	}
	return (0);
}

int		mouse_no_click(int button, int x, int y, t_env *e)
{
	e->mo.m = button;
	e->mo.mx = x;
	e->mo.my = y;
	return (0);
}
