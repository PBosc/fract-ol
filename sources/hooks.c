/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:23:56 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:11:42 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_hook(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_hook(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_equal || keysym == XK_KP_Add)
		fractal->iter += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iter -= 10;
	render(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 1.2;
		fractal->shift_x -= (x - (WIDTH / 2)) * fractal->zoom / 500;
		fractal->shift_y += (y - (HEIGHT / 2)) * fractal->zoom / 500;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 0.8;
		fractal->shift_x += (x - (WIDTH / 2)) * fractal->zoom / 500;
		fractal->shift_y -= (y - (HEIGHT / 2)) * fractal->zoom / 500;
	}
	render(fractal);
	return (0);
}
