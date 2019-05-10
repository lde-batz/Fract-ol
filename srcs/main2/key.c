/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:00:41 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:15:29 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_init_key_fct3(t_graph *win)
{
	int	j;

	j = -1;
	while (++j < 6)
	{
		win->key_fct[69][j].fct = &ft2_head_up;
		win->key_fct[69][j].ok = 1;
		win->key_fct[78][j].fct = &ft2_head_down;
		win->key_fct[78][j].ok = 1;
		if (j % 2 == 1)
		{
			win->key_fct[126][j].fct = &ft2_move_up;
			win->key_fct[126][j].ok = 1;
			win->key_fct[123][j].fct = &ft2_move_left;
			win->key_fct[123][j].ok = 1;
			win->key_fct[125][j].fct = &ft2_move_down;
			win->key_fct[125][j].ok = 1;
			win->key_fct[124][j].fct = &ft2_move_right;
			win->key_fct[124][j].ok = 1;
		}
	}
	j = -1;
	while (++j < 8)
		win->key_fct[28][j].ok = 1;
}

void	ft2_init_key_fct2(t_graph *win)
{
	int	j;

	j = -1;
	while (++j < 8)
	{
		win->key_fct[0][j].fct = &ft2_move_a;
		win->key_fct[0][j].ok = 1;
		win->key_fct[1][j].fct = &ft2_move_s;
		win->key_fct[1][j].ok = 1;
		win->key_fct[2][j].fct = &ft2_move_d;
		win->key_fct[2][j].ok = 1;
		win->key_fct[13][j].fct = &ft2_move_w;
		win->key_fct[13][j].ok = 1;
		win->key_fct[49][j].fct = &ft2_iteration_up;
		win->key_fct[49][j].ok = 1;
		win->key_fct[51][j].fct = &ft2_iteration_down;
		win->key_fct[51][j].ok = 1;
		win->key_fct[53][j].fct = &ft2_esc;
		win->key_fct[53][j].ok = 1;
		win->key_fct[18][j].fct = &ft2_color_change0;
		win->key_fct[18][j].ok = 1;
		win->key_fct[19][j].fct = &ft2_color_change1;
		win->key_fct[19][j].ok = 1;
	}
	ft2_init_key_fct3(win);
}

void	ft2_init_key_fct(t_graph *win)
{
	int i;
	int	j;

	j = -1;
	while (++j < 8)
	{
		i = -1;
		while (++i < 274)
		{
			win->key_fct[i][j].ok = 0;
			win->key_fct[i][j].fct = NULL;
		}
		win->key_fct[20][j].fct = &ft2_color_change2;
		win->key_fct[20][j].ok = 1;
		win->key_fct[21][j].fct = &ft2_color_change3;
		win->key_fct[21][j].ok = 1;
		win->key_fct[23][j].fct = &ft2_color_change4;
		win->key_fct[23][j].ok = 1;
		win->key_fct[22][j].fct = &ft2_color_change5;
		win->key_fct[22][j].ok = 1;
		win->key_fct[26][j].fct = &ft2_color_change6;
		win->key_fct[26][j].ok = 1;
		win->key_fct[28][j].fct = &ft2_color_change7;
	}
	ft2_init_key_fct2(win);
}

void	ft2_esc(void *param)
{
	t_graph	*win;

	win = param;
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}

int		ft2_press_key(int touch, void *param)
{
	t_graph	*win;

	win = param;
	if (win->key_fct[touch][win->fract.type].ok)
		win->key_fct[touch][win->fract.type].fct(win);
	return (0);
}
