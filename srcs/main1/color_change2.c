/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:44:58 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 09:45:43 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_color_change5(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 5;
	win->f_menu.color = 5;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change6(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 6;
	win->f_menu.color = 6;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_color_change7(void *param)
{
	int		i;
	t_graph	*win;

	win = param;
	win->fract.color = 7;
	win->f_menu.color = 7;
	i = -1;
	while (++i < 6)
		win->fract_fct[i].fct(win, &win->menu[i], &win->f_menu);
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
