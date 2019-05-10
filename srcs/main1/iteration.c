/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:40:07 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/11 12:41:27 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_iteration_up(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 6)
		win->fract.max += 10;
	else
		win->fract.koch_n += 1;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
}

void	ft_iteration_down(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 6 && win->fract.max > 10)
	{
		win->fract.max -= 10;
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
	else if (win->fract.type >= 6 && win->fract.koch_n > 0)
	{
		win->fract.koch_n -= 1;
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
}
