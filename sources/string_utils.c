/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibosc <pibosc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:04:39 by pibosc            #+#    #+#             */
/*   Updated: 2023/12/09 01:07:32 by pibosc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

double	atodbl(char *s)
{
	double	res;
	double	dec;

	res = 0;
	dec = 0;
	while (*s && *s != '.')
	{
		res = (res * 10) + (*s - '0');
		++s;
	}
	if (*s == '.')
	{
		++s;
		while (*s)
		{
			dec = (dec * 10) + (*s - '0');
			++s;
		}
	}
	return ((res + (dec / pow(10, ft_strlen(s)))));
}
