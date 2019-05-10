/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:59:09 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:14:48 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_init_fract_fct_init(t_graph *win)
{
	win->f_init_fct[0].fct = &ft2_init_mandel;
	win->f_init_fct[1].fct = &ft2_init_julia;
	win->f_init_fct[2].fct = &ft2_init_mandel_tricorn;
	win->f_init_fct[3].fct = &ft2_init_julia_tricorn;
	win->f_init_fct[4].fct = &ft2_init_mandel_ship;
	win->f_init_fct[5].fct = &ft2_init_julia_ship;
	win->f_init_fct[6].fct = &ft2_init_koch;
	win->f_init_fct[7].fct = &ft2_init_flocon;
}

void	ft2_init_fract_fct(t_graph *win)
{
	win->fract_fct[0].fct = &ft2_print_mandel;
	win->fract_fct[1].fct = &ft2_print_julia;
	win->fract_fct[2].fct = &ft2_print_mandel_tricorn;
	win->fract_fct[3].fct = &ft2_print_julia_tricorn;
	win->fract_fct[4].fct = &ft2_print_mandel_ship;
	win->fract_fct[5].fct = &ft2_print_julia_ship;
	win->fract_fct[6].fct = &ft2_print_koch;
	win->fract_fct[7].fct = &ft2_print_flocon;
}
