/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:44:24 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 09:44:49 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_color_change0(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 0;
	win->f_menu.color = 0;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change1(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 1;
	win->f_menu.color = 1;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change2(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 2;
	win->f_menu.color = 2;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change3(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 3;
	win->f_menu.color = 3;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change4(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 4;
	win->f_menu.color = 4;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
