/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:49:53 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/11 12:50:00 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_zoom1_up(void *param, int x, int y)
{
	t_graph		*win;
	t_fractol	*f;
	double		x_c;
	double		y_c;
	double		diff;

	win = param;
	f = &(win->fract);
	x_c = f->x1 + ((x * (f->x2 - f->x1)) / WIN_H);
	y_c = f->y1 + ((y * (f->y2 - f->y1)) / WIN_H);
	diff = x_c - f->x1;
	diff *= 0.9;
	f->x1 = x_c - diff;
	diff = y_c - f->y1;
	diff *= 0.9;
	f->y1 = y_c - diff;
	diff = f->x2 - x_c;
	diff *= 0.9;
	f->x2 = x_c + diff;
	diff = f->y2 - y_c;
	diff *= 0.9;
	f->y2 = y_c + diff;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_zoom1_down(void *param, int x, int y)
{
	t_graph		*win;
	t_fractol	*f;
	double		x_c;
	double		y_c;
	double		diff;

	win = param;
	f = &(win->fract);
	x_c = f->x1 + ((x * (f->x2 - f->x1)) / WIN_H);
	y_c = f->y1 + ((y * (f->y2 - f->y1)) / WIN_H);
	diff = x_c - f->x1;
	diff *= 1.1;
	f->x1 = x_c - diff;
	diff = y_c - f->y1;
	diff *= 1.1;
	f->y1 = y_c - diff;
	diff = f->x2 - x_c;
	diff *= 1.1;
	f->x2 = x_c + diff;
	diff = f->y2 - y_c;
	diff *= 1.1;
	f->y2 = y_c + diff;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_zoom2_up(void *param, int x, int y)
{
	t_graph		*win;
	t_fractol	*f;
	double		diff;

	win = param;
	f = &(win->fract);
	diff = x - f->koch.x1;
	diff *= 1.1;
	f->koch.x1 = x - diff;
	diff = y - f->koch.y1;
	diff *= 1.1;
	f->koch.y1 = y - diff;
	diff = f->koch.x2 - x;
	diff *= 1.1;
	f->koch.x2 = x + diff;
	diff = f->koch.y2 - y;
	diff *= 1.1;
	f->koch.y2 = y + diff;
	diff = f->koch.x3 - x;
	diff *= 1.1;
	f->koch.x3 = x + diff;
	diff = f->koch.y3 - y;
	diff *= 1.1;
	f->koch.y3 = y + diff;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_zoom2_down(void *param, int x, int y)
{
	t_graph		*win;
	t_fractol	*f;
	double		diff;

	win = param;
	f = &(win->fract);
	diff = x - f->koch.x1;
	diff *= 0.9;
	f->koch.x1 = x - diff;
	diff = y - f->koch.y1;
	diff *= 0.9;
	f->koch.y1 = y - diff;
	diff = f->koch.x2 - x;
	diff *= 0.9;
	f->koch.x2 = x + diff;
	diff = f->koch.y2 - y;
	diff *= 0.9;
	f->koch.y2 = y + diff;
	diff = f->koch.x3 - x;
	diff *= 0.9;
	f->koch.x3 = x + diff;
	diff = f->koch.y3 - y;
	diff *= 0.9;
	f->koch.y3 = y + diff;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
