/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:37:51 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 16:36:39 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		touch(t_env *e)
{
	if (e->k[ESC] == 1)
		exit(0);
	if (e->mo.m == 4)
	{
//		printf("hello --> old x : [%d] | old y : [%d] +++++ new x : [%d] | new y : [%d]\n", e->mo.ox, e->mo.oy, e->mo.mx, e->mo.my);

		e->mo.ofx = e->mo.ox - e->mo.mx;
		e->mo.ofy = e->mo.oy - e->mo.my;
		e->z.x = -(e->mo.mx * (e->mo.ox - e->mo.mx));
		e->z.y = -(e->mo.my * (e->mo.oy - e->mo.my));
		printf("x : [%d] | y : [%d]\n", e->z.x, e->z.y);
	}
	if (e->mo.m == 5)
	{
		printf("bye\n");
	}
	return (0);
}
