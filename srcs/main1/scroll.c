/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:55:14 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 14:30:56 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_scroll_up(t_graph *win)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		win->menu[i].y += 440;
		mlx_put_image_to_window(win->mlx, win->win, win->menu[i].img_ptr,
			win->menu[i].x, win->menu[i].y);
	}
}

void	ft_scroll_down(t_graph *win)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		win->menu[i].y -= 440;
		mlx_put_image_to_window(win->mlx, win->win, win->menu[i].img_ptr,
			win->menu[i].x, win->menu[i].y);
	}
}
