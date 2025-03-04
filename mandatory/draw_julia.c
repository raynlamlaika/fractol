/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:36:01 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 06:00:35 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	helper(t_fractal *frac, double imag, double real)
{
	int		iter;
	double	tmp;

	iter = 0;
	frac->interation = 40;
	while ((real * real + imag * imag) <= 4 && iter < frac->interation)
	{
		tmp = real * real - imag * imag + frac->julia_c_real;
		imag = 2 * real * imag + frac->julia_c_imag;
		real = tmp;
		iter++;
	}
	if (iter == frac->interation)
		frac->color = 0x000000;
	else
		frac->color = (iter * 255 / frac->interation) * frac->color_shift;
	my_mlx_pixel_put(frac);
}

void	draw_julia(t_fractal *frac)
{
	double	real;
	double	imag;

	frac->x_loop = 0;
	while (frac->x_loop < WIDTH)
	{
		frac->y_loop = 0;
		while (frac->y_loop < HEIGHT)
		{
			real = ((frac->x_loop - WIDTH / 2) / (WIDTH * 0.2)) / frac->zoom;
			imag = ((frac->y_loop - HEIGHT / 2) / (HEIGHT * 0.2)) / frac->zoom;
			helper(frac, real, imag);
			frac->y_loop++;
		}
		frac->x_loop++;
	}
}
