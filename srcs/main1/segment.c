/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:20:35 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/09 11:19:34 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_segment_up(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->y1)++;
	}
}

void	ft_segment_down(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->y1)--;
	}
}

void	ft_segment_left(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->x1)--;
	}
}

void	ft_segment_right(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->x1)++;
	}
}

void	ft_print_segment(t_segment *s, t_img *img)
{
	if ((s->dx = s->x2 - s->x1) != 0)
	{
		if (s->dx > 0)
			ft_1st_half(s, img);
		else
			ft_2nd_half(s, img);
	}
	else
	{
		if ((s->dy = s->y2 - s->y1) != 0)
		{
			if (s->dy > 0)
				ft_segment_up(s, img);
			else
			{
				ft_segment_down(s, img);
			}
		}
	}
}
