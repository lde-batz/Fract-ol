/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:45:29 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:07:53 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_init_mouse_fct2(t_graph *win)
{
	int	j;

	j = -1;
	while (++j < 6)
	{
		win->mouse_fct[1][j].ok = 1;
		win->mouse_fct[1][j].fct = &ft_move_param_c;
		win->mouse_fct[4][j].ok = 1;
		win->mouse_fct[4][j].fct = &ft_zoom1_up;
		win->mouse_fct[5][j].ok = 1;
		win->mouse_fct[5][j].fct = &ft_zoom1_down;
	}
	while (j < 8)
	{
		win->mouse_fct[4][j].ok = 1;
		win->mouse_fct[4][j].fct = &ft_zoom2_up;
		win->mouse_fct[5][j].ok = 1;
		win->mouse_fct[5][j++].fct = &ft_zoom2_down;
	}
}

void	ft_init_mouse_fct(t_graph *win)
{
	int i;
	int j;

	j = -1;
	while (++j < 8)
	{
		i = -1;
		while (++i < 8)
		{
			win->mouse_fct[i][j].ok = 0;
			win->mouse_fct[i][j].fct = NULL;
		}
	}
	win->mouse_fct[2][0].ok = 1;
	win->mouse_fct[2][0].fct = &ft_go_julia;
	win->mouse_fct[2][2].ok = 1;
	win->mouse_fct[2][2].fct = &ft_go_julia_tricorn;
	win->mouse_fct[2][4].ok = 1;
	win->mouse_fct[2][4].fct = &ft_go_julia_ship;
	ft_init_mouse_fct2(win);
}

int		ft_clic_mouse(int button, int x, int y, void *param)
{
	t_graph	*win;

	win = param;
	if (x >= 0 && x < WIN_H && y >= 0 && y < WIN_H)
		if (win->mouse_fct[button][win->fract.type].ok)
			win->mouse_fct[button][win->fract.type].fct(win, x, y);
	if (x >= WIN_H && x < WIN_W && y >= 0 && y < WIN_H)
	{
		if (button == 1)
			ft_change_fract(win, y);
		if (button == 4 && win->menu[0].y < 0)
			ft_scroll_up(win);
		if (button == 5 && win->menu[7].y > 880)
			ft_scroll_down(win);
	}
	return (0);
}

int		ft_move_mouse(int x, int y, void *param)
{
	t_graph *wn;

	wn = param;
	if (wn->move_mouse == 1 && wn->fract.type < 6)
	{
		if (x >= 0 && x < WIN_H && y >= 0 && y < WIN_H)
		{
			wn->fract.c_r = wn->fract.x1 + ((x * (wn->fract.x2 -
				wn->fract.x1)) / WIN_H);
			wn->fract.c_i = wn->fract.y1 + ((y * (wn->fract.y2 -
				wn->fract.y1)) / WIN_H);
			wn->f_menu.c_r = wn->fract.c_r;
			wn->f_menu.c_i = wn->fract.c_i;
			if (wn->fract.type % 2 == 1)
			{
				wn->fract_fct[wn->fract.type].fct(wn, &wn->img, &wn->fract);
				wn->fract_fct[wn->fract.type].fct(wn,
					&wn->menu[wn->fract.type], &wn->f_menu);
			}
			else
				wn->fract_fct[wn->fract.type + 1].fct(wn,
					&wn->menu[wn->fract.type + 1], &wn->f_menu);
		}
	}
	return (0);
}
