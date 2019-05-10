/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:52:57 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 09:47:48 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_iteration_color1(t_thread *f)
{
	short	color;

	if (f->i == f->max)
	{
		(f->img->data)[(f->y * f->img->l) + (f->x * 4)] = 0;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 1] = 0;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 2] = 0;
	}
	else if (f->i <= f->max / 2)
	{
		color = ((f->i * 220) / (f->max / 2)) + 25;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4)] = 0;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 1] = 0;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 2] = color;
	}
	else
	{
		color = ((f->i - (f->max / 2)) * 255) / (f->max / 2);
		(f->img->data)[(f->y * f->img->l) + (f->x * 4)] = color;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 1] = color;
		color = 255;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 2] = color;
	}
}

void	ft_iteration_color(t_thread *f)
{
	short	c_r;
	short	c_g;
	short	c_b;

	if (f->color == 7)
		ft_iteration_color1(f);
	else
	{
		if (f->i == f->max)
		{
			c_r = 0;
			c_g = 0;
			c_b = 0;
		}
		else
		{
			c_r = f->c->tab[f->color][f->i % f->c->tab[f->color][9][0]][0];
			c_g = f->c->tab[f->color][f->i % f->c->tab[f->color][9][0]][1];
			c_b = f->c->tab[f->color][f->i % f->c->tab[f->color][9][0]][2];
		}
		(f->img->data)[(f->y * f->img->l) + (f->x * 4)] = c_b;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 1] = c_g;
		(f->img->data)[(f->y * f->img->l) + (f->x * 4) + 2] = c_r;
	}
}
