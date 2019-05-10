/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:21:38 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:02:12 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_check_name2(t_graph *win, char *name)
{
	if (!(ft_strcmp(name, "julia_buring_ship")))
	{
		win->fract.type = 5;
		return ;
	}
	if (!(ft_strcmp(name, "courbe_koch")) || !(ft_strcmp(name, "flocon_koch")))
	{
		if (!(ft_strcmp(name, "courbe_koch")))
			win->fract.type = 6;
		else
			win->fract.type = 7;
		return ;
	}
	ft_putendl("Usage: ./fractol fractale [fractale] [fratale]");
	ft_putendl("  name of fractol:");
	ft_putendl("    --> mandelbrot");
	ft_putendl("    --> julia");
	ft_putendl("    --> mandelbrot_tricorn");
	ft_putendl("    --> julia_tricorn");
	ft_putendl("    --> mandelbrot_buring_ship");
	ft_putendl("    --> julia_buring_ship");
	ft_putendl("    --> courbe_koch");
	ft_putendl("    --> flocon_koch");
	exit(EXIT_FAILURE);
}

void	ft2_check_name(t_graph *win, char *name)
{
	if (!(ft_strcmp(name, "mandelbrot")) || !(ft_strcmp(name, "julia")))
	{
		if (!(ft_strcmp(name, "mandelbrot")))
			win->fract.type = 0;
		else
			win->fract.type = 1;
		return ;
	}
	if (!(ft_strcmp(name, "mandelbrot_tricorn")))
	{
		win->fract.type = 2;
		return ;
	}
	if (!(ft_strcmp(name, "julia_tricorn")))
	{
		win->fract.type = 3;
		return ;
	}
	if (!(ft_strcmp(name, "mandelbrot_buring_ship")))
	{
		win->fract.type = 4;
		return ;
	}
	ft2_check_name2(win, name);
}

void	ft2_init_graph(t_graph *win, char *name)
{
	ft2_check_name(win, name);
	ft2_init_fract_fct_init(win);
	ft2_init_fract_fct(win);
	ft2_init_key_fct(win);
	ft2_init_mouse_fct(win);
	ft2_init_tab_color(win);
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_W, name);
	win->fract.c_r = 0.0;
	win->fract.c_i = -0.8;
	win->fract.head = 2.0;
	win->fract.color = 0;
	win->fract.c = &win->c;
	win->fract.img_x = WIN_W;
	win->move_mouse = 0;
	ft2_new_img(&(win->img), mlx_new_image(win->mlx, WIN_W, WIN_W), WIN_W);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, &(win->img.bpp),
		&(win->img.l), &win->img.endian);
}
