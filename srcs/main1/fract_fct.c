/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:37:51 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 13:58:40 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_init_fract_fct_init(t_graph *win)
{
	win->f_init_fct[0].fct = &ft_init_mandel;
	win->f_init_fct[1].fct = &ft_init_julia;
	win->f_init_fct[2].fct = &ft_init_mandel_tricorn;
	win->f_init_fct[3].fct = &ft_init_julia_tricorn;
	win->f_init_fct[4].fct = &ft_init_mandel_ship;
	win->f_init_fct[5].fct = &ft_init_julia_ship;
	win->f_init_fct[6].fct = &ft_init_koch;
	win->f_init_fct[7].fct = &ft_init_flocon;
}

void	ft_init_fract_fct(t_graph *win)
{
	win->fract_fct[0].fct = &ft_print_mandel;
	win->fract_fct[1].fct = &ft_print_julia;
	win->fract_fct[2].fct = &ft_print_mandel_tricorn;
	win->fract_fct[3].fct = &ft_print_julia_tricorn;
	win->fract_fct[4].fct = &ft_print_mandel_ship;
	win->fract_fct[5].fct = &ft_print_julia_ship;
	win->fract_fct[6].fct = &ft_print_koch;
	win->fract_fct[7].fct = &ft_print_flocon;
}

void	ft_change_fract(t_graph *win, int y)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (y < win->menu[i].y + 440)
		{
			win->f_init_fct[i].fct(win);
			i = 8;
		}
	}
}
