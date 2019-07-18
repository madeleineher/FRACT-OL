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

void	colorkoch(t_env *e, t_kohp tmp, int i)
{
	e->data[0 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = \
		e->colgrad[i % 10];
	e->data[1 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = \
		e->colgrad[i % 10] >> 8;
	e->data[2 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = \
		e->colgrad[i % 10] >> 16;
	e->data[3 + (int)tmp.x * (e->w.bpp / 8) + (int)tmp.y * e->w.sl] = 0;
}

void	colormenu(t_env *e, int i)
{
	int		amp;
	int		lum;

	i = 0;
	e->clr.fq1 = .01;
	e->clr.fq2 = .01;
	e->clr.fq3 = .01;
	amp = 70;
	lum = 170;
	while (i < 10000)
	{
		e->clr.r = sin(e->clr.fq1 * i + 0) * amp + lum;
		e->clr.g = sin(e->clr.fq2 * i + 4) * amp + lum;
		e->clr.b = sin(e->clr.fq3 * i + 2) * amp + lum;
		e->colmenu[i] = (e->clr.r << 16);
		e->colmenu[i] |= (e->clr.g << 8);
		e->colmenu[i] |= (e->clr.b);
		i++;
	}
}

void	color(t_env *e)
{
	int	i;

	i = 0;
	e->pal[0][0] = 0xDAE5CE;
	e->pal[1][0] = 0x80FFC5;
	e->pal[2][0] = 0xEAE7FF;
	e->pal[3][0] = 0xD6EF80;
	e->pal[4][0] = 0xBBBAF2;
	e->pal[5][0] = 0xEDED76;
	e->pal[6][0] = 0xBAA7B0;
	e->pal[7][0] = 0xFFD289;
	e->clr.fq1 = .04;
	e->clr.fq2 = .04;
	e->clr.fq3 = .04;
	while (i < 10000)
	{
		e->clr.r = sin(e->clr.fq1 * i + e->clr.ph1_r) * e->clr.amp + e->clr.lum;
		e->clr.g = sin(e->clr.fq2 * i + e->clr.ph2_g) * e->clr.amp + e->clr.lum;
		e->clr.b = sin(e->clr.fq3 * i + e->clr.ph3_b) * e->clr.amp + e->clr.lum;
		e->colgrad[i] = (e->clr.r << 16);
		e->colgrad[i] |= (e->clr.g << 8);
		e->colgrad[i] |= (e->clr.b);
		i++;
	}
}
