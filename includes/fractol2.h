/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:12:48 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/14 09:59:19 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL2_H
# define FRACTOL2_H

# include "../libft/srcs/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <pthread.h>

# define WIN_W 800
# define THREAD 11

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		endian;
	int		w;
	int		l;
}				t_img;

typedef struct	s_koch
{
	long int	xb;
	long int	yb;
	long int	xc;
	long int	yc;
	long int	xd;
	long int	yd;
	long int	xe;
	long int	ye;
}				t_koch;

typedef struct	s_pt_koch
{
	long int	x1;
	long int	y1;
	long int	x2;
	long int	y2;
	long int	x3;
	long int	y3;
}				t_pt_koch;

typedef struct	s_segment
{
	long int	x1;
	long int	y1;
	long int	x2;
	long int	y2;
	long int	dx;
	long int	dy;
	long int	e;
}				t_segment;

typedef struct	s_color
{
	short		tab[7][10][3];
}				t_color;

typedef struct	s_mouse_fct
{
	int		ok;
	void	(*fct)(void *, int, int);
}				t_mouse_fct;

typedef struct	s_key_fct
{
	int		ok;
	void	(*fct)(void *);
}				t_key_fct;

typedef struct	s_thread
{
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			max;
	int			img_x;
	int			img_y;
	double		z_r;
	double		z_i;
	double		c_r;
	double		c_i;
	int			i;
	double		n;
	double		tmp;
	int			color;
	t_color		*c;
	t_img		*img;
}				t_thread;

typedef struct	s_fractol
{
	int			type;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	int			max;
	int			img_x;
	double		c_r;
	double		c_i;
	double		head;
	int			koch_n;
	int			color;
	t_pt_koch	koch;
	t_color		*c;
	pthread_t	ptr_thread[11];
}				t_fractol;

typedef struct	s_init_fct
{
	void	(*fct)(void *);
}				t_init_fct;

typedef struct	s_fract_fct
{
	void	(*fct)(void *, t_img *, t_fractol *);
}				t_fract_fct;

typedef struct	s_graph
{
	void		*mlx;
	void		*win;
	int			move_mouse;
	t_img		img;
	t_fractol	fract;
	t_fract_fct	fract_fct[8];
	t_init_fct	f_init_fct[8];
	t_key_fct	key_fct[274][8];
	t_mouse_fct	mouse_fct[8][8];
	t_color		c;
}				t_graph;

void			ft2_init_graph(t_graph *win, char *name);
void			ft2_init_fract_fct(t_graph *win);
void			ft2_init_fract_fct_init(t_graph *win);
void			ft2_init_key_fct(t_graph *win);
void			ft2_init_mouse_fct(t_graph *win);
void			ft2_init_tab_color(t_graph *win);
void			ft2_init_tab_color6(t_graph *win);
void			ft2_new_img(t_img *img, void *img_ptr, int w);
void			ft2_clear_img(t_img *img);
void			ft2_init_mandel(void *param);
void			ft2_init_julia(void *param);
void			ft2_init_mandel_tricorn(void *param);
void			ft2_init_julia_tricorn(void *param);
void			ft2_init_mandel_ship(void *param);
void			ft2_init_julia_ship(void *param);
void			ft2_init_koch(void *param);
void			ft2_init_flocon(void *param);
void			ft2_print_mandel(void *param, t_img *img, t_fractol *f);
void			ft2_print_julia(void *param, t_img *img, t_fractol *f);
void			ft2_print_mandel_tricorn(void *param, t_img *img, t_fractol *f);
void			ft2_print_julia_tricorn(void *param, t_img *img, t_fractol *f);
void			ft2_print_mandel_ship(void *param, t_img *img, t_fractol *f);
void			ft2_print_julia_ship(void *param, t_img *img, t_fractol *f);
void			ft2_print_koch(void *param, t_img *img, t_fractol *f);
void			ft2_print_flocon(void *param, t_img *img, t_fractol *f);
void			ft2_koch_rec(t_segment *s, t_img *img, int n);
void			ft2_print_segment(t_segment *s, t_img *img);
void			ft2_1st_half(t_segment *s, t_img *img);
void			ft2_2nd_half(t_segment *s, t_img *img);
void			ft2_segment_left(t_segment *s, t_img *img);
void			ft2_segment_right(t_segment *s, t_img *img);
void			ft2_iteration_color(t_thread *f);
int				ft2_press_key(int touch, void *param);
void			ft2_esc(void *param);
void			ft2_iteration_up(void *param);
void			ft2_iteration_down(void *param);
void			ft2_head_up(void *param);
void			ft2_head_down(void *param);
void			ft2_move_w(void *param);
void			ft2_move_a(void *param);
void			ft2_move_s(void *param);
void			ft2_move_d(void *param);
void			ft2_move_up(void *param);
void			ft2_move_left(void *param);
void			ft2_move_down(void *param);
void			ft2_move_right(void *param);
void			ft2_color_change0(void *param);
void			ft2_color_change1(void *param);
void			ft2_color_change2(void *param);
void			ft2_color_change3(void *param);
void			ft2_color_change4(void *param);
void			ft2_color_change5(void *param);
void			ft2_color_change6(void *param);
void			ft2_color_change7(void *param);
int				ft2_clic_mouse(int button, int x, int y, void *param);
void			ft2_zoom1_up(void *param, int x, int y);
void			ft2_zoom1_down(void *param, int x, int y);
void			ft2_zoom2_up(void *param, int x, int y);
void			ft2_zoom2_down(void *param, int x, int y);
void			ft2_move_param_c(void *param, int x, int y);
int				ft2_move_mouse(int x, int y, void *param);
int				ft2_expose(void *param);

#endif
