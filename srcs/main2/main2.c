/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:05:03 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:23:10 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft_main2(t_graph *win0, t_graph *win1, char **argv)
{
	win0->mlx = mlx_init();
	win1->mlx = win0->mlx;
	ft2_init_graph(win0, argv[1]);
	ft2_init_graph(win1, argv[2]);
	win0->f_init_fct[win0->fract.type].fct(win0);
	win1->f_init_fct[win1->fract.type].fct(win1);
}

void	main2(int argc, char **argv)
{
	t_graph	win[argc - 1];

	ft_main2(&win[0], &win[1], argv);
	if (argc == 4)
	{
		win[2].mlx = win[0].mlx;
		ft2_init_graph(&(win[2]), argv[3]);
		win[2].f_init_fct[win[2].fract.type].fct(&win[2]);
	}
	mlx_hook(win[0].win, 2, 0, ft2_press_key, (&win[0]));
	mlx_hook(win[0].win, 4, 0, ft2_clic_mouse, (&win[0]));
	mlx_hook(win[0].win, 6, 0, ft2_move_mouse, (&win[0]));
	mlx_hook(win[0].win, 12, 0, ft2_expose, (&win[0]));
	mlx_hook(win[1].win, 2, 0, ft2_press_key, (&win[1]));
	mlx_hook(win[1].win, 4, 0, ft2_clic_mouse, (&win[1]));
	mlx_hook(win[1].win, 6, 0, ft2_move_mouse, (&win[1]));
	mlx_hook(win[1].win, 12, 0, ft2_expose, (&win[1]));
	if (argc == 4)
	{
		mlx_hook(win[2].win, 2, 0, ft2_press_key, (&win[2]));
		mlx_hook(win[2].win, 4, 0, ft2_clic_mouse, (&win[2]));
		mlx_hook(win[2].win, 6, 0, ft2_move_mouse, (&win[2]));
		mlx_hook(win[2].win, 12, 0, ft2_expose, (&win[2]));
	}
	mlx_loop(win[0].mlx);
}
