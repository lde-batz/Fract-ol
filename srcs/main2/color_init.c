/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:54:54 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:56:26 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_init_tab_color5(t_graph *win)
{
	int	i;

	win->c.tab[4][2][2] = 187;
	win->c.tab[4][3][0] = 51;
	win->c.tab[4][3][1] = 255;
	win->c.tab[4][3][2] = 221;
	win->c.tab[4][4][0] = 25;
	win->c.tab[4][4][1] = 255;
	win->c.tab[4][4][2] = 255;
	win->c.tab[4][5][0] = 0;
	win->c.tab[4][5][1] = 255;
	win->c.tab[4][5][2] = 255;
	win->c.tab[4][6][0] = 0;
	win->c.tab[4][6][1] = 230;
	win->c.tab[4][6][2] = 191;
	win->c.tab[4][7][0] = 0;
	win->c.tab[4][7][1] = 230;
	win->c.tab[4][7][2] = 153;
	win->c.tab[4][9][0] = 8;
	i = -1;
	while (++i < 6)
		win->c.tab[5][i][1] = 255;
	win->c.tab[5][0][0] = 212;
	win->c.tab[5][0][2] = 0;
	ft2_init_tab_color6(win);
}

void	ft2_init_tab_color4(t_graph *win)
{
	win->c.tab[3][3][0] = 179;
	win->c.tab[3][3][1] = 25;
	win->c.tab[3][3][2] = 255;
	win->c.tab[3][4][0] = 212;
	win->c.tab[3][4][1] = 0;
	win->c.tab[3][4][2] = 255;
	win->c.tab[3][5][0] = 191;
	win->c.tab[3][5][1] = 0;
	win->c.tab[3][5][2] = 230;
	win->c.tab[3][6][0] = 136;
	win->c.tab[3][6][1] = 0;
	win->c.tab[3][6][2] = 204;
	win->c.tab[3][7][0] = 102;
	win->c.tab[3][7][1] = 0;
	win->c.tab[3][7][2] = 204;
	win->c.tab[3][9][0] = 8;
	win->c.tab[4][0][0] = 0;
	win->c.tab[4][0][1] = 255;
	win->c.tab[4][0][2] = 128;
	win->c.tab[4][1][0] = 25;
	win->c.tab[4][1][1] = 255;
	win->c.tab[4][1][2] = 140;
	win->c.tab[4][2][0] = 51;
	win->c.tab[4][2][1] = 255;
	ft2_init_tab_color5(win);
}

void	ft2_init_tab_color3(t_graph *win)
{
	win->c.tab[2][3][1] = 155;
	win->c.tab[2][3][2] = 51;
	win->c.tab[2][4][0] = 255;
	win->c.tab[2][4][1] = 179;
	win->c.tab[2][4][2] = 22;
	win->c.tab[2][5][0] = 255;
	win->c.tab[2][5][1] = 170;
	win->c.tab[2][5][2] = 0;
	win->c.tab[2][6][0] = 230;
	win->c.tab[2][6][1] = 155;
	win->c.tab[2][6][2] = 0;
	win->c.tab[2][7][0] = 230;
	win->c.tab[2][7][1] = 76;
	win->c.tab[2][7][2] = 0;
	win->c.tab[2][9][0] = 8;
	win->c.tab[3][0][0] = 76;
	win->c.tab[3][0][1] = 0;
	win->c.tab[3][0][2] = 230;
	win->c.tab[3][1][0] = 85;
	win->c.tab[3][1][1] = 0;
	win->c.tab[3][1][2] = 255;
	win->c.tab[3][2][0] = 140;
	win->c.tab[3][2][1] = 25;
	win->c.tab[3][2][2] = 255;
	ft2_init_tab_color4(win);
}

void	ft2_init_tab_color2(t_graph *win)
{
	win->c.tab[1][1][2] = 60;
	win->c.tab[1][2][0] = 44;
	win->c.tab[1][2][1] = 141;
	win->c.tab[1][2][2] = 128;
	win->c.tab[1][3][0] = 242;
	win->c.tab[1][3][1] = 192;
	win->c.tab[1][3][2] = 75;
	win->c.tab[1][4][0] = 227;
	win->c.tab[1][4][1] = 119;
	win->c.tab[1][4][2] = 71;
	win->c.tab[1][5][0] = 179;
	win->c.tab[1][5][1] = 33;
	win->c.tab[1][5][2] = 40;
	win->c.tab[1][9][0] = 6;
	win->c.tab[2][0][0] = 255;
	win->c.tab[2][0][1] = 42;
	win->c.tab[2][0][2] = 0;
	win->c.tab[2][1][0] = 255;
	win->c.tab[2][1][1] = 64;
	win->c.tab[2][1][2] = 25;
	win->c.tab[2][2][0] = 255;
	win->c.tab[2][2][1] = 119;
	win->c.tab[2][2][2] = 51;
	win->c.tab[2][3][0] = 255;
	ft2_init_tab_color3(win);
}

void	ft2_init_tab_color(t_graph *win)
{
	win->c.tab[0][0][0] = 217;
	win->c.tab[0][0][1] = 235;
	win->c.tab[0][0][2] = 255;
	win->c.tab[0][1][0] = 71;
	win->c.tab[0][1][1] = 89;
	win->c.tab[0][1][2] = 129;
	win->c.tab[0][2][0] = 12;
	win->c.tab[0][2][1] = 33;
	win->c.tab[0][2][2] = 58;
	win->c.tab[0][3][0] = 71;
	win->c.tab[0][3][1] = 89;
	win->c.tab[0][3][2] = 129;
	win->c.tab[0][4][0] = 118;
	win->c.tab[0][4][1] = 137;
	win->c.tab[0][4][2] = 166;
	win->c.tab[0][5][0] = 187;
	win->c.tab[0][5][1] = 205;
	win->c.tab[0][5][2] = 226;
	win->c.tab[0][9][0] = 6;
	win->c.tab[1][0][0] = 242;
	win->c.tab[1][0][1] = 192;
	win->c.tab[1][0][2] = 75;
	win->c.tab[1][1][0] = 123;
	win->c.tab[1][1][1] = 23;
	ft2_init_tab_color2(win);
}
