/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:00 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:10:21 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"


#define ERROR_MESSAGE "Usage : \"./fractol mandelbrot\" or \"./fractol julia <value_1> <value_2>\" or \"./fractol burning_ship\"\n"
#define WIDTH				800
#define	HEIGHT				800
#define BLACK       		0x000000
#define WHITE       		0xFFFFFF
#define RED         		0xFF0000
#define GREEN       		0x00FF00
#define BLUE        		0x0000FF
#define MAGENTA_BURST   	0xFF00FF
#define LIME_SHOCK      	0xCCFF00
#define NEON_ORANGE     	0xFF6600
#define PSYCHEDELIC_PURPLE 	0x660066
#define AQUA_DREAM      	0x33CCCC
#define HOT_PINK        	0xFF66B2
#define ELECTRIC_BLUE   	0x0066FF
#define LAVA_RED        	0xFF3300

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iter;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
double		atodbl(char *s);
void		init_data(t_fractal *fractal);
void		render(t_fractal *fractal);
double		do_calc(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_hook(int keysym, t_fractal *fractal);
int			close_hook(t_fractal *fractal);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);
void		calc_burning_ship(t_complex *z, t_complex *c);

#endif
