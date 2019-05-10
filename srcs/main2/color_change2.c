/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:10:55 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:11:43 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_color_change5(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 5;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change6(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 6;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_color_change7(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.color = 7;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
