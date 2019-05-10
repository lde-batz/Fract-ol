/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flocon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:37:35 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/09 11:06:46 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_print_flocon(void *param, t_img *img, t_fractol *f)
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
	ft_clear_img(img);
	ft_koch_rec(&koch[0], img, f->koch_n);
	ft_koch_rec(&koch[1], img, f->koch_n);
	ft_koch_rec(&koch[2], img, f->koch_n);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, img->x, img->y);
}

void	ft_init_flocon(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 7;
	win->fract.koch_n = 3;
	win->fract.koch.x1 = 200;
	win->fract.koch.y1 = 950;
	win->fract.koch.x2 = 660;
	win->fract.koch.y2 = 153;
	win->fract.koch.x3 = 1120;
	win->fract.koch.y3 = 950;
	ft_print_flocon(win, &win->img, &win->fract);
}
