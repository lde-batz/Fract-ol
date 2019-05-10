/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:22:27 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 15:57:39 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_check_name2(t_graph *win, char *name)
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

void	ft_check_name(t_graph *win, char *name)
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
	ft_check_name2(win, name);
}

void	ft_init_graph3(t_graph *win)
{
	ft_new_img(&(win->menu[3]), mlx_new_image(win->mlx, 440, 440), MENU_H, 4);
	win->menu[3].data = mlx_get_data_addr(win->menu[3].img_ptr,
		&(win->menu[3].bpp), &(win->menu[3].l), &win->img.endian);
	ft_print_julia_tricorn(win, &win->menu[3], &win->f_menu);
	ft_new_img(&(win->menu[4]), mlx_new_image(win->mlx, 440, 440), MENU_H, 5);
	win->menu[4].data = mlx_get_data_addr(win->menu[4].img_ptr,
		&(win->menu[4].bpp), &(win->menu[4].l), &win->img.endian);
	ft_print_mandel_ship(win, &win->menu[4], &win->f_menu);
	ft_new_img(&(win->menu[5]), mlx_new_image(win->mlx, 440, 440), MENU_H, 6);
	win->menu[5].data = mlx_get_data_addr(win->menu[5].img_ptr,
		&(win->menu[5].bpp), &(win->menu[5].l), &win->img.endian);
	ft_print_julia_ship(win, &win->menu[5], &win->f_menu);
	ft_new_img(&(win->menu[6]), mlx_new_image(win->mlx, 440, 440), MENU_H, 7);
	win->menu[6].data = mlx_get_data_addr(win->menu[6].img_ptr,
		&(win->menu[6].bpp), &(win->menu[6].l), &win->img.endian);
	ft_print_koch(win, &win->menu[6], &win->f_menu);
	ft_new_img(&(win->menu[7]), mlx_new_image(win->mlx, 440, 440), MENU_H, 8);
	win->menu[7].data = mlx_get_data_addr(win->menu[7].img_ptr,
		&(win->menu[7].bpp), &(win->menu[7].l), &win->img.endian);
	ft_print_flocon(win, &win->menu[7], &win->f_menu);
}

void	ft_init_graph2(t_graph *win)
{
	win->f_menu.img_x = MENU_H;
	win->f_menu.koch_n = 3;
	win->f_menu.koch.x1 = 200 / 3;
	win->f_menu.koch.y1 = 950 / 3;
	win->f_menu.koch.x2 = 660 / 3;
	win->f_menu.koch.y2 = 153 / 3;
	win->f_menu.koch.x3 = 1120 / 3;
	win->f_menu.koch.y3 = 950 / 3;
	win->move_mouse = 0;
	ft_new_img(&(win->img), mlx_new_image(win->mlx, WIN_H, WIN_H), WIN_H, 0);
	win->img.data = mlx_get_data_addr(win->img.img_ptr, &(win->img.bpp),
		&(win->img.l), &win->img.endian);
	ft_new_img(&(win->menu[0]), mlx_new_image(win->mlx, 440, 440), MENU_H, 1);
	win->menu[0].data = mlx_get_data_addr(win->menu[0].img_ptr,
		&(win->menu[0].bpp), &(win->menu[0].l), &win->img.endian);
	ft_print_mandel(win, &win->menu[0], &win->f_menu);
	ft_new_img(&(win->menu[1]), mlx_new_image(win->mlx, 440, 440), MENU_H, 2);
	win->menu[1].data = mlx_get_data_addr(win->menu[1].img_ptr,
		&(win->menu[1].bpp), &(win->menu[1].l), &win->img.endian);
	ft_print_julia(win, &win->menu[1], &win->f_menu);
	ft_new_img(&(win->menu[2]), mlx_new_image(win->mlx, 440, 440), MENU_H, 3);
	win->menu[2].data = mlx_get_data_addr(win->menu[2].img_ptr,
		&(win->menu[2].bpp), &(win->menu[2].l), &win->img.endian);
	ft_print_mandel_tricorn(win, &win->menu[2], &win->f_menu);
	ft_init_graph3(win);
}

void	ft_init_graph(t_graph *win, char *name)
{
	ft_check_name(win, name);
	ft_init_fract_fct_init(win);
	ft_init_fract_fct(win);
	ft_init_key_fct(win);
	ft_init_mouse_fct(win);
	ft_init_tab_color(win);
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "FACT'OL");
	win->fract.c_r = 0.0;
	win->fract.c_i = -0.8;
	win->fract.head = 2.0;
	win->fract.color = 0;
	win->fract.c = &win->c;
	win->fract.img_x = WIN_H;
	win->f_menu.x1 = -2.0;
	win->f_menu.x2 = 2.0;
	win->f_menu.y1 = -2.0;
	win->f_menu.y2 = 2.0;
	win->f_menu.max = 50;
	win->f_menu.c_r = 0.0;
	win->f_menu.c_i = -0.8;
	win->f_menu.head = 2.0;
	win->f_menu.color = 0;
	win->f_menu.c = &win->c;
	ft_init_graph2(win);
}
