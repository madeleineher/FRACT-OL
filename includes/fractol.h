/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 07:58:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/06/10 17:34:56 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <assert.h>
# include <stdio.h> //remove me

# define WIDTH  800 
# define HEIGHT 800
# define X_MIN	-2.182
# define X_MAX	2.6558
# define Y_MIN	0
# define Y_MAX	9.9983

# define ESC 	53
# define MOUSEM	6

typedef struct	s_fer
{
	double		x;
	double		y;
	double		nx;
	double		ny;
}				t_fer;


typedef struct	s_jul
{
	int			x;
	int			y;
	int			n;
	int			nmax;
	float		w;
	float		h;
	float		xmax;
	float		xmin;
	float		ymin;
	float		ymax;
	float		dx;
	float		dy;
	float		ty;
	float		tx;
	float		a;
	float		b;
	float		two_a;
	float		two_b;
	float		two_ab;
}				t_jul;

typedef struct	s_man
{
	int			i;
	int			j;
	int			n;
	int			nmax;
	float		w;
	float		h;
	float		xmax;
	float		xmin;
	float		ymin;
	float		ymax;
	float		dx;
	float		dy;
	float		ty;
	float		tx;
	float		a;
	float		b;
	float		two_a;
	float		two_b;
	float		two_ab;
}				t_man;

typedef struct	s_win
{
	void		*wp;
	void		*mp;
	void		*ip;
	int			sl;
	int			bpp;
	int			end;
}				t_win;

typedef struct	s_env
{
	char		*fractol;
	char		*data;
	int			k[300];
	int			mx;
	int			my;
	t_win		w;
	t_man		m;
	t_jul		j;
	t_fer		f;
}				t_env;

int				start(t_env *e);
int				touch(t_env *e);
void			mandelbrot(t_env *e);
void			julia(t_env *e);
void			fern(t_env *e);
int				main(int argc, char **argv);

#endif
