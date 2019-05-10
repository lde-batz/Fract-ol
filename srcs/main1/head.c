/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:39:29 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:24:31 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_head_up(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 2 && win->fract.head < 9.9)
	{
		win->fract.head += 0.1;
		win->f_menu.head += 0.1;
		win->fract_fct[win->fract.type].fct(win, &win->menu[win->fract.type],
			&win->f_menu);
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
}

void	ft_head_down(void *param)
{
	t_graph	*win;

	win = param;
	if (win->fract.type < 2 && win->fract.head > 2.0)
	{
		win->fract.head -= 0.1;
		win->f_menu.head -= 0.1;
		win->fract_fct[win->fract.type].fct(win, &win->menu[win->fract.type],
			&win->f_menu);
		win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	}
}
