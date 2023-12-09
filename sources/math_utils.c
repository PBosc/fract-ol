/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:20 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:05:18 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	do_calc(double unscaled_num, double new_min,
					double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num)
		/ (old_max) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

void	calc_burning_ship(t_complex *z, t_complex *c)
{
	double	tmp;

	z->x = fabs(z->x);
	z->y = fabs(z->y);
	tmp = 2 * z->x * z->y + c->y;
	z->x = z->x * z->x - z->y * z->y + c->x;
	z->y = tmp;
}
