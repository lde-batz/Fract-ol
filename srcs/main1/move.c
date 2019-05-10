/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:42:57 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/11 15:43:15 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_move_w(void *param)
{
	double	diff;
	t_graph	*win;

	win = param;
	if (win->fract.type < 6)
	{
		diff = win->fract.y2 - win->fract.y1;
		win->fract.y1 += diff * 0.01;
		win->fract.y2 += diff * 0.01;
	}
	else
	{
		win->fract.koch.y1 -= 10;
		win->fract.koch.y2 -= 10;
		win->fract.koch.y3 -= 10;
	}
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_move_a(void *param)
{
	double	diff;
	t_graph	*win;

	win = param;
	if (win->fract.type < 6)
	{
		diff = win->fract.x2 - win->fract.x1;
		win->fract.x1 += diff * 0.01;
		win->fract.x2 += diff * 0.01;
	}
	else
	{
		win->fract.koch.x1 -= 10;
		win->fract.koch.x2 -= 10;
		win->fract.koch.x3 -= 10;
	}
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_move_s(void *param)
{
	double	diff;
	t_graph	*win;

	win = param;
	if (win->fract.type < 6)
	{
		diff = win->fract.y2 - win->fract.y1;
		win->fract.y1 -= diff * 0.01;
		win->fract.y2 -= diff * 0.01;
	}
	else
	{
		win->fract.koch.y1 += 10;
		win->fract.koch.y2 += 10;
		win->fract.koch.y3 += 10;
	}
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_move_d(void *param)
{
	double	diff;
	t_graph	*win;

	win = param;
	if (win->fract.type < 6)
	{
		diff = win->fract.x2 - win->fract.x1;
		win->fract.x1 -= diff * 0.01;
		win->fract.x2 -= diff * 0.01;
	}
	else
	{
		win->fract.koch.x1 += 10;
		win->fract.koch.x2 += 10;
		win->fract.koch.x3 += 10;
	}
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_move_param_c(void *param, int x, int y)
{
	t_graph	*win;

	win = param;
	x = 0;
	y = 0;
	if (win->move_mouse == 0)
		win->move_mouse = 1;
	else
		win->move_mouse = 0;
}
