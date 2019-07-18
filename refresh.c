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
