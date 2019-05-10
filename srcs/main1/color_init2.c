/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:10:44 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 09:51:53 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_init_tab_color7(t_graph *win)
{
	win->c.tab[6][2][1] = 255;
	win->c.tab[6][2][2] = 0;
	win->c.tab[6][3][0] = 0;
	win->c.tab[6][3][1] = 255;
	win->c.tab[6][3][2] = 42;
	win->c.tab[6][4][0] = 0;
	win->c.tab[6][4][1] = 255;
	win->c.tab[6][4][2] = 213;
	win->c.tab[6][5][0] = 0;
	win->c.tab[6][5][1] = 128;
	win->c.tab[6][5][2] = 255;
	win->c.tab[6][6][0] = 42;
	win->c.tab[6][6][1] = 0;
	win->c.tab[6][6][2] = 255;
	win->c.tab[6][7][0] = 212;
	win->c.tab[6][7][1] = 0;
	win->c.tab[6][7][2] = 255;
	win->c.tab[6][8][0] = 255;
	win->c.tab[6][8][1] = 0;
	win->c.tab[6][8][2] = 128;
	win->c.tab[6][9][0] = 9;
}

void	ft_init_tab_color6(t_graph *win)
{
	win->c.tab[5][1][0] = 217;
	win->c.tab[5][1][2] = 25;
	win->c.tab[5][2][0] = 187;
	win->c.tab[5][2][2] = 51;
	win->c.tab[5][3][0] = 153;
	win->c.tab[5][3][2] = 51;
	win->c.tab[5][4][0] = 25;
	win->c.tab[5][4][2] = 255;
	win->c.tab[5][5][0] = 0;
	win->c.tab[5][5][2] = 255;
	win->c.tab[5][6][0] = 115;
	win->c.tab[5][6][1] = 230;
	win->c.tab[5][6][2] = 0;
	win->c.tab[5][7][0] = 153;
	win->c.tab[5][7][1] = 230;
	win->c.tab[5][7][2] = 0;
	win->c.tab[5][9][0] = 8;
	win->c.tab[6][0][0] = 255;
	win->c.tab[6][0][1] = 42;
	win->c.tab[6][0][2] = 0;
	win->c.tab[6][1][0] = 255;
	win->c.tab[6][1][1] = 213;
	win->c.tab[6][1][2] = 0;
	win->c.tab[6][2][0] = 128;
	ft_init_tab_color7(win);
}
