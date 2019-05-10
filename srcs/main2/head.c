/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:22:47 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:24:51 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_head_up(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 2 && win->fract.head < 9.9)
	{
		win->fract.head += 0.1;
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
}

void	ft2_head_down(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 2 && win->fract.head > 2.0)
	{
		win->fract.head -= 0.1;
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
}
