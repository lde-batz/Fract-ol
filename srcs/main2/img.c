/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:12:33 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:06:08 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

void	ft2_new_img(t_img *img, void *img_ptr, int w)
{
	img->img_ptr = img_ptr;
	img->bpp = 4;
	img->w = w;
	img->l = w * 4;
}

void	ft2_clear_img(t_img *img)
{
	int	i;

	i = 0;
	while (i < img->w * img->l)
		(img->data)[i++] = 0;
}
