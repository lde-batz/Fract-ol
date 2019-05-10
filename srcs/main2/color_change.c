/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:09:22 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:10:42 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_color_change0(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 0;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change1(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 1;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change2(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 2;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change3(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 3;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change4(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 4;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
