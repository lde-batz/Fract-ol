/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:39:00 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:57:26 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_koch_rec2(t_segment *s, t_koch *k, t_img *img, int n)
{
	k->xb = s->x2;
	k->yb = s->y2;
	k->xc = s->x1 + ((s->x2 - s->x1) / 3);
	k->yc = s->y1 + ((s->y2 - s->y1) / 3);
	k->xd = s->x1 + ((2 * (s->x2 - s->x1)) / 3);
	k->yd = s->y1 + ((2 * (s->y2 - s->y1)) / 3);
	k->xe = k->xc + ((k->xd - k->xc) * 0.5) - ((k->yd - k->yc) * -0.866);
	k->ye = k->yc + ((k->yd - k->yc) * 0.5) + ((k->xd - k->xc) * -0.866);
	s->x2 = k->xc;
	s->y2 = k->yc;
	ft2_koch_rec(s, img, n - 1);
	s->x1 = k->xc;
	s->y1 = k->yc;
	s->x2 = k->xe;
	s->y2 = k->ye;
}

void	ft2_koch_rec(t_segment *s, t_img *img, int n)
{
	t_koch	k;

	if (n == 0)
	{
		if ((s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w) ||
				(s->x2 >= 0 && s->x2 < img->w && s->y2 >= 0 && s->y2 < img->w))
			ft2_print_segment(s, img);
	}
	else
	{
		ft2_koch_rec2(s, &k, img, n);
		ft2_koch_rec(s, img, n - 1);
		s->x1 = k.xe;
		s->y1 = k.ye;
		s->x2 = k.xd;
		s->y2 = k.yd;
		ft2_koch_rec(s, img, n - 1);
		s->x1 = k.xd;
		s->y1 = k.yd;
		s->x2 = k.xb;
		s->y2 = k.yb;
		ft2_koch_rec(s, img, n - 1);
	}
}

void	ft2_print_koch(void *param, t_img *img, t_fractol *f)
{
	t_segment	koch;
	t_graph		*win;

	win = param;
	koch.x1 = f->koch.x1;
	koch.y1 = f->koch.y1;
	koch.x2 = f->koch.x3;
	koch.y2 = f->koch.y3;
	ft2_clear_img(img);
	ft2_koch_rec(&koch, img, f->koch_n);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, 0, 0);
}

void	ft2_init_koch(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 6;
	win->fract.koch_n = 3;
	win->fract.koch.x1 = 170;
	win->fract.koch.y1 = 950 / 2;
	win->fract.koch.x3 = 630;
	win->fract.koch.y3 = 950 / 2;
	ft2_print_koch(win, &win->img, &win->fract);
}
