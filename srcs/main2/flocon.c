/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flocon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:19:00 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:59:32 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_print_flocon(void *param, t_img *img, t_fractol *f)
{
	t_segment	koch[3];
	t_graph		*win;

	win = param;
	koch[0].x1 = f->koch.x1;
	koch[0].y1 = f->koch.y1;
	koch[0].x2 = f->koch.x2;
	koch[0].y2 = f->koch.y2;
	koch[1].x1 = f->koch.x2;
	koch[1].y1 = f->koch.y2;
	koch[1].x2 = f->koch.x3;
	koch[1].y2 = f->koch.y3;
	koch[2].x1 = f->koch.x3;
	koch[2].y1 = f->koch.y3;
	koch[2].x2 = f->koch.x1;
	koch[2].y2 = f->koch.y1;
	ft2_clear_img(img);
	ft2_koch_rec(&koch[0], img, f->koch_n);
	ft2_koch_rec(&koch[1], img, f->koch_n);
	ft2_koch_rec(&koch[2], img, f->koch_n);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, 0, 0);
}

void	ft2_init_flocon(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 7;
	win->fract.koch_n = 3;
	win->fract.koch.x1 = 170;
	win->fract.koch.y1 = 550;
	win->fract.koch.x2 = 400;
	win->fract.koch.y2 = 150;
	win->fract.koch.x3 = 630;
	win->fract.koch.y3 = 550;
	ft2_print_flocon(win, &win->img, &win->fract);
}
