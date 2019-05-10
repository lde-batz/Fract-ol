/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:03:19 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 14:26:16 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_move_up(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_i -= 0.005;
	win->f_menu.c_i = win->fract.c_i;
	if (win->fract.type % 2 == 1)
	{
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
		win->fract_fct[win->fract.type].fct(win,
			&win->menu[win->fract.type], &win->f_menu);
	}
	else
		win->fract_fct[win->fract.type + 1].fct(win,
			&win->menu[win->fract.type + 1], &win->f_menu);
}

void	ft_move_left(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_r -= 0.005;
	win->f_menu.c_r = win->fract.c_r;
	if (win->fract.type % 2 == 1)
	{
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
		win->fract_fct[win->fract.type].fct(win,
			&win->menu[win->fract.type], &win->f_menu);
	}
	else
		win->fract_fct[win->fract.type + 1].fct(win,
			&win->menu[win->fract.type + 1], &win->f_menu);
}

void	ft_move_down(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_i += 0.005;
	win->f_menu.c_i = win->fract.c_i;
	if (win->fract.type % 2 == 1)
	{
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
		win->fract_fct[win->fract.type].fct(win,
			&win->menu[win->fract.type], &win->f_menu);
	}
	else
		win->fract_fct[win->fract.type + 1].fct(win,
			&win->menu[win->fract.type + 1], &win->f_menu);
}

void	ft_move_right(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_r += 0.005;
	win->f_menu.c_r = win->fract.c_r;
	if (win->fract.type % 2 == 1)
	{
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
		win->fract_fct[win->fract.type].fct(win,
			&win->menu[win->fract.type], &win->f_menu);
	}
	else
		win->fract_fct[win->fract.type + 1].fct(win,
			&win->menu[win->fract.type + 1], &win->f_menu);
}
