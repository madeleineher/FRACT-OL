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
	ft_bzero(e->data, sizeof(int) * WIDTH * HEIGHT);
	start(e);
}

void		textingthree(t_env *e, char *str)
{
	if (e->k[H] == 1)
		mlx_string_put(e->w.mp, e->w.wp, WIDTH + 110, 485, WH, "NEGATIVE");
	else
		mlx_string_put(e->w.mp, e->w.wp, WIDTH + 110, 485, WH, "POSITIVE");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 610, WH, "ITERATIONS : ");
	str = ft_itoa(e->xy.nmax);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 630, WH, str);
	free(str);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 55, HEIGHT - 30, WH, "MHERNAND");
}

void		textingtwo(t_env *e)
{
	char	*str;

	str = NULL;
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 360, WH, "RGB PHASES :");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 380, WH, "RED : Z   ->");
	str = ft_itoa(e->clr.ph1_r);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 155, 380, WH, str);
	free(str);
	str = ft_itoa(e->clr.ph2_g);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 400, WH, "GREEN : X ->");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 155, 400, WH, str);
	free(str);
	str = ft_itoa(e->clr.ph3_b);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 420, WH, "BLUE : C  ->");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 155, 420, WH, str);
	free(str);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 445, WH, "RGB FREQUENCIES :");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 465, WH, "NEG / POS : H");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 485, WH, "STATUS :");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 505, WH, "RED : V");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 525, WH, "GREEN : G");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 545, WH, "BLUE : B");
	textingthree(e, str);
}

void		texting(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = 799;
	colormenu(e, i);
	while (++i < HEIGHT)
	{
		while (++j < 1000)
			mlx_pixel_put(e->w.mp, e->w.wp, j, i, e->colmenu[i % 10000]);
		j = 799;
	}
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 50, 20, WH, "FRACT'OL");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 50, 70, WH, e->fractol);
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 120, WH, "MOVE : W, A, S, D");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 145, WH, "NEXT FRACTOL : N");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 170, WH, "PAUSE : SPACEBAR");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 195, WH, "ITERATE : I, U");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 220, WH, "ZOOM : Q, E");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 245, WH, "RESET : R");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 270, WH, "COLOR AMPLITUDE :");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 290, WH, "INCREASE : K");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 25, 310, WH, "DECREASE : L");
	mlx_string_put(e->w.mp, e->w.wp, WIDTH + 15, 335, WH, "EXIT : ESC");
	textingtwo(e);
}
