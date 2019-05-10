/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:44:44 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:17:20 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_move_up(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_i -= 0.005;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_move_left(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_r -= 0.005;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_move_down(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_i += 0.005;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft2_move_right(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.c_r += 0.005;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}
