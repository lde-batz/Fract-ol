/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_ship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:39:55 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/18 13:04:17 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	*ft2_thr_ship1(void *param)
{
	t_thread	*f;

	f = param;
	while (++(f->y) < f->img_y)
	{
		f->x = -1;
		while (++(f->x) < f->img_x)
		{
			f->c_r = f->x1 + ((f->x * (f->x2 - f->x1)) / f->img_x);
			f->c_i = f->y1 + ((f->y * (f->y2 - f->y1)) / f->img_x);
			f->z_r = 0.0;
			f->z_i = 0.0;
			f->i = -1;
			while (++(f->i) < f->max && (f->z_r * f->z_r +
					f->z_i * f->z_i) < 4.0)
			{
				f->tmp = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
				f->z_i = fabs((2.0 * f->z_r * f->z_i) + f->c_i);
				f->z_r = fabs(f->tmp);
			}
			ft2_iteration_color(f);
		}
	}
	pthread_exit(NULL);
}

void	ft2_init_mandel_ship_thr(t_fractol *f, t_img *img, t_thread thr[THREAD])
{
	int	i;

	i = -1;
	while (++i < THREAD)
	{
		thr[i].max = f->max;
		thr[i].y = i * (f->img_x / THREAD) - 1;
		thr[i].x1 = f->x1;
		thr[i].x2 = f->x2;
		thr[i].y1 = f->y1;
		thr[i].y2 = f->y2;
		thr[i].n = f->head;
		thr[i].img_x = f->img_x;
		thr[i].img_y = (i + 1) * (f->img_x / THREAD);
		thr[i].img = img;
		thr[i].color = f->color;
		thr[i].c = f->c;
	}
}

void	ft2_print_mandel_ship(void *param, t_img *img, t_fractol *f)
{
	t_thread	thread[THREAD];
	t_graph		*win;
	int			i;

	win = param;
	ft2_init_mandel_ship_thr(f, img, thread);
	i = -1;
	while (++i < THREAD)
		pthread_create(&f->ptr_thread[i], NULL, ft2_thr_ship1, &thread[i]);
	i = -1;
	while (++i < THREAD)
		pthread_join(f->ptr_thread[i], NULL);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, 0, 0);
}

void	ft2_init_mandel_ship(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 4;
	win->fract.max = 100;
	win->fract.x1 = -2.5;
	win->fract.x2 = 1.5;
	win->fract.y1 = -2.0;
	win->fract.y2 = 2.0;
	ft2_print_mandel_ship(win, &win->img, &win->fract);
}
