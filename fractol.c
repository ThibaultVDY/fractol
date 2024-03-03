/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:53:24 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:18 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot") + 1)) || (argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen("julia") + 1)))
	{
		instructions;
		argv[1][0] = ft_toupper(argv[1][0]);
		fract.title = argv[1];
		if (!ft_strncmp(fract.title, "Julia", 5))
		{
			fract.julia_r = atod(argv[2]);
			fract.julia_i = atod(argv[3]);
		}
		fractol_init(&fract);
		fractol_render(&fract);
		mlx_loop(fract.mlx_connect);
		return (0);
	}
	ft_printf("Invalid intput\n");
	ft_printf("Try;\n<./fractol mandelbrot> or\n<./fractol julia number number>");
	exit(EXIT_FAILURE);
}
