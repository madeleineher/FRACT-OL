/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:36:37 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/02 15:38:02 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	range(t_env *e)
{
	e->xy.xmin = -e->xy.w/2;
	e->xy.xmax = e->xy.xmin + e->xy.w;
	e->xy.ymin = -e->xy.h / 2;
	e->xy.ymax = e->xy.ymin + e->xy.h;
}
