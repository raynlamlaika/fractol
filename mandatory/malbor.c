/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malbor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:08:41 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 06:15:04 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	helper(t_fractal *frac, double imag, double real)
{
	int		iter;
	double	newimg;
	double	newreal;
	double	tmp;

	iter = 0;
	frac->interation = 20;
	newreal = 0.0;
	newimg = 0.0;
	while ((newimg * newimg + newreal * newreal) <= 4 \
			&& frac->interation > iter)
	{
		tmp = newreal * newreal - newimg * newimg + real;
		newimg = 2 * newreal * newimg + imag;
		newreal = tmp;
		iter++;
	}
	if (iter == frac->interation)
		frac->color = 0x000000;
	else
		frac->color = (iter * 255 / frac->interation) * frac->color_shift;
	my_mlx_pixel_put(frac);
}

void	draw_mlbro(t_fractal *frac)
{
	double	real;
	double	imag;

	frac->x_loop = 0;
	frac->position_y = -2;
	frac->position_x = 2;
	while (frac->x_loop < WIDTH)
	{
		frac->y_loop = 0;
		while (frac->y_loop < HEIGHT)
		{
			real = ((frac->x_loop - WIDTH / 2) / (WIDTH * 0.2)) / frac->zoom;
			imag = ((frac->y_loop - HEIGHT / 2) / (HEIGHT * 0.2)) / frac->zoom;
			helper(frac, imag, real);
			frac->y_loop++;
		}
		frac->x_loop++;
	}
}
