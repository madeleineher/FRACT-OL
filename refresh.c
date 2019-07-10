/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 11:38:05 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/09 11:38:07 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		quit(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}

void	blackout(t_env *e)
{
	int		i;
	int		j;

	j = -1;
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
			*(int *)&e->data[i * (e->w.bpp / 8) + j * e->w.sl] = 0x000000;
	}
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
	start(e);
}