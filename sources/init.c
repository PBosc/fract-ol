/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:03 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:10:16 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iter = 25;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	hooks(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_hook, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress,
		ButtonPressMask, mouse_hook, fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify,
		StructureNotifyMask, close_hook, fractal);
}

void	init_data(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx, WIDTH,
			HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	hooks(fractal);
	data_init(fractal);
}
