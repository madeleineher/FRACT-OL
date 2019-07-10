/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 07:58:21 by mhernand          #+#    #+#             */
/*   Updated: 2019/07/05 16:50:53 by mhernand         ###   ########.fr       */
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
# include <pthread.h>
# include <stdio.h> //remove me !!!!!!!!!!!

# define WIDTH			800
# define HEIGHT 		800
# define THREADS		4

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
# define N				45
# define KEY_SPACEBAR	49
# define MOUSEM			6

typedef struct			s_fer
{
	double				x;
	double				y;
	double				nx;
	double				ny;
	double				random;
}						t_fer;

typedef struct			s_bre
{
	int					dx;
	int					dy;
	int					ix;
	int					iy;
	int					tdx;
	int					tdy;
}						t_bre;

typedef struct			s_sie
{
	int					ax;
	int					ay;
	int					bx;
	int					by;
	int					cx;
	int					cy;
	int					rx;
	int					ry;
	double				r;
}						t_sie;

typedef struct			s_jul
{
	int					x;
	int					y;
	int					n;
	float				dx;
	float				dy;
	float				ty;
	float				tx;
	float				a;
	float				b;
	float				two_a;
	float				two_b;
	float				two_ab;
}						t_jul;

typedef struct			s_burn
{
	int					x;
	int					y;
	int					n;
	float				dx;
	float				dy;
	float				ty;
	float				tx;
	float				a;
	float				b;
	float				two_a;
	float				two_b;
	float				two_ab;
}						t_burn;

typedef struct			s_man
{
	int					x;
	int					y;
	int					n;
	float				dx;
	float				dy;
	float				ty;
	float				tx;
	float				a;
	float				b;
	float				two_a;
	float				two_b;
	float				two_ab;
}						t_man;

typedef struct			s_tri
{
	int					x;
	int					y;
	int					n;
	float				dx;
	float				dy;
	float				ty;
	float				tx;
	float				a;
	float				b;
	float				two_a;
	float				two_b;
	float				two_ab;
}						t_tri;

typedef struct			s_kohp
{
	double				x;
	double				y;
}						t_kohp;

typedef struct			s_koch
{
	int					iter;
	t_kohp				kp[6]; //koch points
	t_bre				n; // bre
}						t_koch;

typedef struct			s_win
{
	void				*wp;
	void				*mp;
	void				*ip;
	int					sl;
	int					bpp;
	int					end;
}						t_win;

typedef struct			s_mos
{
	int					mx;
	int					my;
	int					m;
}						t_mos;

typedef struct			s_xy
{
	int					nmax;
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	double				w;
	double				h;
	double				mre;
	double				mri;
	double				zoom;
	double				w_t;
	double				h_t;
}						t_xy;

typedef struct			s_env
{
	char				*fractol;
	char				*data;
	int					k[300];
	int					pal[8][5];
	int					c;
	int					starth;
	int					endth;	
	t_mos				mo;
	t_xy				xy;
	t_win				w;
	t_man				m;
	t_jul				j;
	t_burn				b;
	t_fer				f;
	t_sie				s;
	t_tri				t;
	t_koch				o;
}						t_env;

typedef struct			s_thr
{
	t_env				*env;
	int					nth;
}						t_thr;

void					start(t_env *e);
void					setfractol(t_env *e);
int						touch(t_env *e);
int						touchtwomuch(t_env *e);
void					blackout(t_env *e);
int						quit(t_env *e);
int						key_press(int key, t_env *e);
int						key_release(int key, t_env *e);
int						mouse_move(int x, int y, t_env *e);
int						mouse_click(int	button, int x, int y, t_env *e);
int						mouse_no_click(int button, int x, int y, t_env *e);
void					mandelbrot(t_env *e, t_man m);
void					julia(t_env *e, t_jul j);
void					fern(t_env *e, t_fer f);
void					koch(t_env *e);
void					sierpinski(t_env *e);
void					burn(t_env *e, t_burn b);
void					tricorn(t_env *e, t_tri t);
void					color(t_env *e);
void					texting(t_env *e);
void					setfractol(t_env *e);
int						main(int argc, char **argv);

#endif
