/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:13:32 by lde-batz          #+#    #+#             */
/*   Updated: 2019/02/12 17:14:30 by lde-batz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol1.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		ft_putendl("Usage: ./fractol fractale [fractale] [fratale]");
		ft_putendl("  name of fractol:");
		ft_putendl("    --> mandelbrot");
		ft_putendl("    --> julia");
		ft_putendl("    --> mandelbrot_tricorn");
		ft_putendl("    --> julia_tricorn");
		ft_putendl("    --> mandelbrot_buring_ship");
		ft_putendl("    --> julia_buring_ship");
		ft_putendl("    --> courbe_koch");
		ft_putendl("    --> flocon_koch");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
		main1(argv[1]);
	else
		main2(argc, argv);
}
