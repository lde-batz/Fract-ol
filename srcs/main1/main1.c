/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:21:08 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 15:05:48 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	main1(char *argv)
{
	t_graph	win;

	ft_init_graph(&win, argv);
	win.f_init_fct[win.fract.type].fct(&win);
	mlx_hook(win.win, 2, 0, ft_press_key, &win);
	mlx_hook(win.win, 4, 0, ft_clic_mouse, &win);
	mlx_hook(win.win, 6, 0, ft_move_mouse, &win);
	mlx_hook(win.win, 12, 0, ft_expose, &win);
	mlx_loop(win.mlx);
}
