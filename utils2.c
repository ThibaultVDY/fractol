/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-monn <tle-monn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:27 by tle-monn          #+#    #+#             */
/*   Updated: 2024/02/26 16:20:37 by tle-monn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_printf("\nWelcome to the fractal exploration!\nSadly, MiniLibX's limited capabilities result in slow rendering 😞\n");
	ft_printf("\nTo move the fractal:	Press keys: W, A, S, D or Left, Right, Up, Down arrows\n");
	ft_printf("To zoom in:		Scroll mouse wheel up\n");
	ft_printf("To zoom out:		Scroll mouse wheel down\n");
	ft_printf("To switch colours:	Press: Space bar\n");
	ft_printf("To increase iterations:	Press key: + (from the number pad)\n");
	ft_printf("To decrease iterations:	Press key: -\n");
	ft_printf("To rotate Julia:	Mouse left or right click\n");
	ft_printf("To quit:		Press key: ESC or click X on window, or ^C on command line\n");
	ft_printf("\nTry: <./fractal julia -0.4 +0.6> or\n<./fractol julia -0.835 -0.2321>\n");
	ft_printf("\nWARNING: Attempting to resize or maximize the window will lose you to the black abyss!\n");
}

void	malloc_error(void)
{
	perror("MALLOC EROR: ");
	exit(EXIT_FAILURE);
}

void	zoom_in(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoomFactor;

	zoomFactor = 0.95;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoomFactor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoomFactor);
	fract->zoom *= zoomFactor;
}

void	zoom_out(t_fractol *fract, double mouse_r, double mouse_i)
{
	double	zoomFactor;

	zoomFactor = 1.01;
	fract->shift_r += (mouse_r - fract->shift_r) * (1 - zoomFactor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoomFactor);
	fract->zoom *= zoomFactor;
}
