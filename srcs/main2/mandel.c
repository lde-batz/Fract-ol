/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:39:10 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/18 13:08:17 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	*ft2_thr_mandl2(void *param)
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
			while (++f->i < f->max && (f->z_r * f->z_r + f->z_i * f->z_i) < 4.0)
			{
				f->tmp = pow((f->z_r * f->z_r + f->z_i * f->z_i), (f->n / 2))
					* cos(f->n * atan2(f->z_i, f->z_r)) + f->c_r;
				f->z_i = pow((f->z_r * f->z_r + f->z_i * f->z_i), (f->n / 2))
					* sin(f->n * atan2(f->z_i, f->z_r)) + f->c_i;
				f->z_r = f->tmp;
			}
			ft2_iteration_color(f);
		}
	}
	pthread_exit(NULL);
}

void	*ft2_thr_mandel(void *param)
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
			while (++(f->i) < f->max && (f->z_r * f->z_r + f->z_i
					* f->z_i) < 4.0)
			{
				f->tmp = (f->z_r * f->z_r) - (f->z_i * f->z_i);
				f->z_i = (2.0 * f->z_r * f->z_i) + f->c_i;
				f->z_r = f->tmp + f->c_r;
			}
			ft2_iteration_color(f);
		}
	}
	pthread_exit(NULL);
}

void	ft2_init_mandel_thr(t_fractol *f, t_img *img, t_thread thread[THREAD])
{
	int	i;

	i = -1;
	while (++i < THREAD)
	{
		thread[i].max = f->max;
		thread[i].y = i * (f->img_x / THREAD) - 1;
		thread[i].x1 = f->x1;
		thread[i].x2 = f->x2;
		thread[i].y1 = f->y1;
		thread[i].y2 = f->y2;
		thread[i].n = f->head;
		thread[i].img_x = f->img_x;
		thread[i].img_y = (i + 1) * (f->img_x / THREAD);
		thread[i].img = img;
		thread[i].color = f->color;
		thread[i].c = f->c;
	}
}

void	ft2_print_mandel(void *param, t_img *img, t_fractol *f)
{
	t_thread	thread[THREAD];
	t_graph		*win;
	int			i;

	win = param;
	ft2_init_mandel_thr(f, img, thread);
	i = -1;
	while (++i < THREAD)
	{
		if (f->head == 2.0)
			pthread_create(&f->ptr_thread[i], NULL, ft2_thr_mandel, &thread[i]);
		else
			pthread_create(&f->ptr_thread[i], NULL, ft2_thr_mandl2, &thread[i]);
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(f->ptr_thread[i], NULL);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, 0, 0);
}

void	ft2_init_mandel(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 0;
	win->fract.max = 100;
	win->fract.x1 = -2.5;
	win->fract.x2 = 1.5;
	win->fract.y1 = -2.0;
	win->fract.y2 = 2.0;
	ft2_print_mandel(win, &win->img, &win->fract);
}
