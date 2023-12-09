/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:25:47 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:28:39 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	parse_frac_type(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel_burning_ship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ((do_calc(x, -2, 2, WIDTH)) * fractal->zoom) + fractal->shift_x;
	z.y = (do_calc(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	parse_frac_type(&z, &c, fractal);
	z.x = 0;
	z.y = 0;
	while (i < fractal->iter + log(1 / fractal->zoom))
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = do_calc(i, BLACK, WHITE, fractal->iter);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		calc_burning_ship(&z, &c);
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ((do_calc(x, -2, 2, WIDTH)) * fractal->zoom) + fractal->shift_x;
	z.y = (do_calc(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	parse_frac_type(&z, &c, fractal);
	while (i < fractal->iter + log(1 / fractal->zoom))
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = do_calc(i, BLACK, WHITE, fractal->iter);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

void	render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "burning_ship", 12))
				handle_pixel_burning_ship(x, y, fractal);
			else
				handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
