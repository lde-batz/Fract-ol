/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:02:51 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:22:14 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_init_mouse_fct2(t_graph *win)
{
	int	j;

	j = -1;
	while (++j < 6)
	{
		win->mouse_fct[1][j].ok = 1;
		win->mouse_fct[1][j].fct = &ft2_move_param_c;
		win->mouse_fct[4][j].ok = 1;
		win->mouse_fct[4][j].fct = &ft2_zoom1_up;
		win->mouse_fct[5][j].ok = 1;
		win->mouse_fct[5][j].fct = &ft2_zoom1_down;
	}
	while (j < 8)
	{
		win->mouse_fct[4][j].ok = 1;
		win->mouse_fct[4][j].fct = &ft2_zoom2_up;
		win->mouse_fct[5][j].ok = 1;
		win->mouse_fct[5][j++].fct = &ft2_zoom2_down;
	}
}

void	ft2_init_mouse_fct(t_graph *win)
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
	ft2_init_mouse_fct2(win);
}

int		ft2_clic_mouse(int button, int x, int y, void *param)
{
	t_graph	*win;

	win = param;
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_W)
		if (win->mouse_fct[button][win->fract.type].ok)
			win->mouse_fct[button][win->fract.type].fct(win, x, y);
	return (0);
}

int		ft2_move_mouse(int x, int y, void *param)
{
	t_graph *win;

	win = param;
	if (win->move_mouse == 1 && win->fract.type % 2 == 1 &&
			win->fract.type != 7)
	{
		if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_W)
		{
			win->fract.c_r = win->fract.x1 + ((x * (win->fract.x2 -
				win->fract.x1)) / WIN_W);
			win->fract.c_i = win->fract.y1 + ((y * (win->fract.y2 -
				win->fract.y1)) / WIN_W);
			win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
		}
	}
	return (0);
}
