/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:23:41 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:13:52 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (4 == ac && !ft_strncmp(av[1], "julia", 5))
		|| (2 == ac && !ft_strncmp(av[1], "burning_ship", 12)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = 1 / atodbl(av[2]);
			fractal.julia_y = 1 / atodbl(av[3]);
		}
		init_data(&fractal);
		render(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
