/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:36:01 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/27 18:30:33 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
		frac->color = (iter * 255 / frac->interation) * 0x010101;
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
			real = (frac->x_loop - frac->position_x) \
					* 4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
			imag = (frac->y_loop - frac->position_y) \
					* 4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;
			helper(frac, real, imag);
			frac->y_loop++;
		}
		frac->x_loop++;
	}
}
