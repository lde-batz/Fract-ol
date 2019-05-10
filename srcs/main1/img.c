/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:53:13 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/11 14:05:02 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

void	ft_new_img(t_img *img, void *img_ptr, int w, int nb)
{
	img->img_ptr = img_ptr;
	img->bpp = 4;
	img->w = w;
	img->l = w * 4;
	if (nb == 0)
	{
		img->x = 0;
		img->y = 0;
	}
	else
	{
		img->x = 1320;
		img->y = (nb - 1) * 440;
	}
}

void	ft_clear_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < img->w * img->l)
		(img->data)[i++] = 0;
}
