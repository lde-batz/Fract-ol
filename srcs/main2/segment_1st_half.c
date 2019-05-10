/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_1st_half.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:51:46 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:53:28 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_1st_octant(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->x1)++;
		if ((s->e -= s->dy) < 0)
		{
			(s->y1)++;
			s->e += s->dx;
		}
	}
}

void	ft2_2nd_octant(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	s->e = s->dy;
	s->dx *= 2;
	s->dy *= 2;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->y1)++;
		if ((s->e -= s->dx) < 0)
		{
			(s->x1)++;
			s->e += s->dy;
		}
	}
}

void	ft2_8th_octant(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	s->e = s->dx;
	s->dx *= 2;
	s->dy *= 2;
	while (s->x1 != s->x2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->x1)++;
		if ((s->e += s->dy) < 0)
		{
			(s->y1)--;
			s->e += s->dx;
		}
	}
}

void	ft2_7th_octant(t_segment *s, t_img *img)
{
	short	color;

	color = 255;
	s->e = s->dy;
	s->dx *= 2;
	s->dy *= 2;
	while (s->y1 != s->y2)
	{
		if (s->x1 >= 0 && s->x1 < img->w && s->y1 >= 0 && s->y1 < img->w)
		{
			(img->data)[(s->y1 * img->l) + (s->x1 * 4)] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 1] = color;
			(img->data)[(s->y1 * img->l) + (s->x1 * 4) + 2] = color;
		}
		(s->y1)--;
		if ((s->e += s->dx) > 0)
		{
			(s->x1)++;
			s->e += s->dy;
		}
	}
}

void	ft2_1st_half(t_segment *s, t_img *img)
{
	if ((s->dy = s->y2 - s->y1) != 0)
	{
		if (s->dy > 0)
		{
			if (s->dx >= s->dy)
				ft2_1st_octant(s, img);
			else
				ft2_2nd_octant(s, img);
		}
		else
		{
			if (s->dx >= -(s->dy))
				ft2_8th_octant(s, img);
			else
				ft2_7th_octant(s, img);
		}
	}
	else
		ft2_segment_right(s, img);
}
