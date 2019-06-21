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

void	color2(t_env *e)
{
	e->pal[4][0] = 0xBBBAF2;
	e->pal[4][1] = 0xD8BAF2;
	e->pal[4][2] = 0xF09ED8;
	e->pal[4][3] = 0xF0508F;
	e->pal[4][4] = 0xF04648;
	e->pal[5][0] = 0xEDED76;
	e->pal[5][1] = 0xFF9060;
	e->pal[5][2] = 0xFF6542;
	e->pal[5][3] = 0xFD5200;
	e->pal[5][4] = 0xD34300;
	e->pal[6][0] = 0xBAA7B0;
	e->pal[6][1] = 0xB2ABBF;
	e->pal[6][2] = 0xB1B5C8;
	e->pal[6][3] = 0xBFD5E2;
	e->pal[6][4] = 0xC7EBF0;
	e->pal[7][0] = 0xFFD289;
	e->pal[7][1] = 0xFACC6B;
	e->pal[7][2] = 0xFFD131;
	e->pal[7][3] = 0xF5B82E;
	e->pal[7][4] = 0xF4AC32;
}

void	color(t_env *e)
{
	e->pal[0][0] = 0xDAE5CE;
	e->pal[0][1] = 0xE8CDC5;
	e->pal[0][2] = 0xFFBACE;
	e->pal[0][3] = 0xEF90AC;
	e->pal[0][4] = 0xBD5E6E;
	e->pal[1][0] = 0x80FFC5;
	e->pal[1][1] = 0x23FFAF;
	e->pal[1][2] = 0x35CC7B;
	e->pal[1][3] = 0x3A903A;
	e->pal[1][4] = 0x27630D;
	e->pal[2][0] = 0xEAE7FF;
	e->pal[2][1] = 0xF6D6E8;
	e->pal[2][2] = 0xC6D3E5;
	e->pal[2][3] = 0x9AD3F9;
	e->pal[2][4] = 0x75D4FF;
	e->pal[3][0] = 0xD6EF80;
	e->pal[3][1] = 0xECFFC3;
	e->pal[3][2] = 0xBEEFD6;
	e->pal[3][3] = 0xB4E6D9;
	e->pal[3][4] = 0x7DD2CE;
	color2(e);
}
