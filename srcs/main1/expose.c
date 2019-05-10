/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:07:27 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 15:09:05 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol1.h"

int	ft_expose(void *param)
{
	t_graph	*win;

	win = param;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	return (0);
}
