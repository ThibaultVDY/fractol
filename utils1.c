/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:08:06 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/26 16:12:43 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(t_map_coords coords)
{
	return ((coords.new_max - coords.new_min) * (coords.unscaled_num - coords.old_min) / (coords.old_max - coords.old_min) + coords.new_min);
}

t_fractol	square_complex(t_fractol z1, t_fractol z2)
{
	t_fractol	result;

	result.cmplx_r = z1.cmplx_r + z2.cmplx_r;
	result.cmplx_i = z1.cmplx_i + z2.cmplx_i;
	return (result);
}

double	atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
