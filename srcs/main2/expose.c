/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:16:52 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 16:17:02 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol2.h"

int	ft2_expose(void *param)
{
	t_graph	*win;

	win = param;
	win->fract_fct[win->fract.type].fct(win, &win->img, &win->fract);
	return (0);
}
