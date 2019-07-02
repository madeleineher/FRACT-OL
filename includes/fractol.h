/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 07:58:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/02 15:40:38 by mhernand         ###   ########.fr       */
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

# define WIDTH			800 
# define HEIGHT 		800
# define COL			8

# define ESC 			53
# define H				4
# define R				15
# define C				8
# define W				13
# define A				0
# define S				1
# define D				2
# define I				34
# define U				32

# define Q				12
# define E				14

# define KEY_SPACEBAR	49
# define MOUSEM			6

typedef struct	s_fer
{
	double		x;
	double		y;
	double		nx;
	double		ny;
	double		random;
}				t_fer;

typedef struct	s_sie
{
	int			ax;
	int			ay;
	int			bx;
	int			by;
	int			cx;
	int			cy;
	int			rx;
	int			ry;
	double		r;
}				t_sie;

typedef struct	s_jul
{
	int			x;
	int			y;
	int			n;
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

typedef struct	s_mos
{
	int			mx;
	int			my;
	int			ox;
	int			oy;
	int			ofx;
	int			ofy;
	int			m;
}				t_mos;

typedef struct	s_zoom
{
	int			x;
	int			y;
}				t_zoom;	

typedef struct	s_xy
{
	int			nmax;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		w;
	double		h;
	double		xcenter;
	double		ycenter;
	double		mRe;
	double		mRi;
	double		zoom;
	double		w_t;
	double		h_t;
}				t_xy;

typedef struct	s_env
{
	char		*fractol;
	char		*data;
	int			k[300];
	int			pal[8][5];
	int			c;
	t_mos		mo;
	t_xy		xy;
	t_win		w;
	t_man		m;
	t_jul		j;
	t_fer		f;
	t_sie		s;
	t_zoom		z;
}				t_env;

int				start(t_env *e);
int				touch(t_env *e);
void			blackout(t_env *e);
int				mouse_move(int x, int y, t_env *e);
int				mouse_click(int	button, int x, int y, t_env *e);
int				mouse_no_click(int button, int x, int y, t_env *e);
void			mandelbrot(t_env *e);
void			julia(t_env *e);
void			fern(t_env *e);
void			koch(t_env *e);
void			sierpinski(t_env *e);
void			color(t_env *e);
void			texting(t_env *e);
void			setfractol(t_env *e);
int				main(int argc, char **argv);

#endif
