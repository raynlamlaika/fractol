/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:36:01 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/26 16:55:15 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	helper(t_fractal *frac, int x, int y, double imag, double real)
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
	my_mlx_pixel_put(frac, x, y);
}

void	draw_julia(t_fractal *frac)
{
	int		x;
	int		y;
	double	real;
	double	imag;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = (x - frac->position_x) * 4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
			imag = (y - frac->position_y) * 4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;
			helper(frac, x, y, real, imag);
			y++;
		}
		x++;
	}
}
