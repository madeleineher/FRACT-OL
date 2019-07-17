/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:27:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/21 16:17:04 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	colorkoch(t_env *e, t_kohp tmp)
{
	e->data[0 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = 0;
	e->data[1 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = e->pal[e->c][0] >> 8;
	e->data[2 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = e->pal[e->c][0] >> 16;
	e->data[3 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = e->pal[e->c][0] >> 24;
}

void	color(t_env *e)
{
	int	i = 0;
	
	i = 0;
	e->c = 0;
	e->pal[0][0] = 0xDAE5CE;
	e->pal[1][0] = 0x80FFC5;
	e->pal[2][0] = 0xEAE7FF;
	e->pal[3][0] = 0xD6EF80;
	e->pal[4][0] = 0xBBBAF2;
	e->pal[5][0] = 0xEDED76;
	e->pal[6][0] = 0xBAA7B0;
	e->pal[7][0] = 0xFFD289;
	e->clr.fq1 = .1;
	e->clr.fq2 = .1;
	e->clr.fq3 = .1;
	while (i < 10000)
	{
		e->clr.r = sin(e->clr.fq1 * i + 0) * e->clr.amp + e->clr.lum;
		e->clr.g = sin(e->clr.fq2 * i + 4) * e->clr.amp + e->clr.lum;
		e->clr.b = sin(e->clr.fq3 * i + 2) * e->clr.amp + e->clr.lum;
		e->colgrad[i] = (e->clr.r << 16);
		e->colgrad[i] |= (e->clr.g << 8);
		e->colgrad[i] |= (e->clr.b);
		// printf("b : [%d]\n", e->clr.b);
		i++;
	}
}
