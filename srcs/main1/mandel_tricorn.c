/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel_tricorn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:31:57 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/18 13:05:12 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	*ft_thr_tricorn1(void *param)
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
			while (++(f->i) < f->max && (f->z_r * f->z_r + f->z_i *
					f->z_i) < 4.0)
			{
				f->tmp = (f->z_r * f->z_r) - (f->z_i * f->z_i);
				f->z_i = (-2.0 * f->z_r * f->z_i) + f->c_i;
				f->z_r = f->tmp + f->c_r;
			}
			ft_iteration_color(f);
		}
	}
	pthread_exit(NULL);
}

void	ft_init_mandel_tri_thr(t_fractol *f, t_img *img, t_thread thr[THREAD])
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
		thr[i].color = f->color;
		thr[i].c = f->c;
		thr[i].img_y = (i + 1) * (f->img_x / THREAD);
		thr[i].img = img;
	}
}

void	ft_print_mandel_tricorn(void *param, t_img *img, t_fractol *f)
{
	t_thread	thread[THREAD];
	t_graph		*win;
	int			i;

	win = param;
	ft_init_mandel_tri_thr(f, img, thread);
	i = -1;
	while (++i < THREAD)
		pthread_create(&f->ptr_thread[i], NULL, ft_thr_tricorn1, &thread[i]);
	i = -1;
	while (++i < THREAD)
		pthread_join(f->ptr_thread[i], NULL);
	mlx_put_image_to_window(win->mlx, win->win, img->img_ptr, img->x, img->y);
}

void	ft_init_mandel_tricorn(void *param)
{
	t_graph	*win;

	win = param;
	win->fract.type = 2;
	win->fract.max = 100;
	win->fract.x1 = -2.5;
	win->fract.x2 = 1.5;
	win->fract.y1 = -2.0;
	win->fract.y2 = 2.0;
	ft_print_mandel_tricorn(win, &win->img, &win->fract);
}
