/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 08:48:02 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/06 13:15:59 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	start(t_env *e)
{	
	if (ft_strcmp(e->fractol, "Mandelbrot") == 0)
		mandelbrot(e);
	else if (ft_strcmp(e->fractol, "Julia") == 0)
		julia(e);
	//else if (ft_strcmp(e->fractol, "Koch") == 0)
	//	koch(e);
	//else if (ft_strcmp(e->fractol, "Fern") == 0)
	//	fern(e);
	//else if (ft_strcmp(e->fractol, "Sierpinski") == 0)
	//	sierpinski(e);
	//else if (ft_strcmp(e->fractol, "Tree") == 0)
	//	tree(e);
	mlx_put_image_to_window(e->w.mp, e->w.wp, e->w.ip, 0, 0);
}
