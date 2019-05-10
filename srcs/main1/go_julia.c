/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:46:50 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/11 12:49:07 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_go_julia(void *param, int x, int y)
{
	t_graph		*win;

	win = param;
	win->fract.c_r = -2.0 + ((x * 4.0) / WIN_H);
	win->fract.c_i = -2.0 + ((y * 4.0) / WIN_H);
	win->f_menu.c_r = win->fract.c_r;
	win->f_menu.c_i = win->fract.c_i;
	ft_init_julia(win);
	ft_print_julia(win, &win->menu[1], &win->f_menu);
}

void	ft_go_julia_tricorn(void *param, int x, int y)
{
	t_graph		*win;

	win = param;
	win->fract.c_r = -2.0 + ((x * 4.0) / WIN_H);
	win->fract.c_i = -2.0 + ((y * 4.0) / WIN_H);
	win->f_menu.c_r = win->fract.c_r;
	win->f_menu.c_i = win->fract.c_i;
	ft_init_julia_tricorn(win);
	ft_print_julia_tricorn(win, &win->menu[3], &win->f_menu);
}

void	ft_go_julia_ship(void *param, int x, int y)
{
	t_graph		*win;

	win = param;
	win->fract.c_r = -2.0 + ((x * 4.0) / WIN_H);
	win->fract.c_i = -2.0 + ((y * 4.0) / WIN_H);
	win->f_menu.c_r = win->fract.c_r;
	win->f_menu.c_i = win->fract.c_i;
	ft_init_julia_ship(win);
	ft_print_julia_ship(win, &win->menu[5], &win->f_menu);
}
