/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malbor_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:08:41 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/27 18:31:58 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	helper(t_fractal *frac, double imag, double real)
{
	int		iter;
	double	newimg;
	double	newreal;
	double	tmp;

	iter = 0;
	frac->interation = 70;
	newreal = 0.0;
	newimg = 0.0;
	while ((newimg * newimg + newreal * newreal) \
			<= 4 && frac->interation > iter)
	{
		tmp = newreal * newreal - newimg * newimg + real;
		newimg = 2 * newreal * newimg + imag;
		newreal = tmp;
		iter++;
	}
	if (iter == frac->interation)
		frac->color = 0x000000;
	else
		frac->color = (iter * 255 / frac->interation) * 0x010100;
	my_mlx_pixel_put(frac);
}

void	draw_mlbro(t_fractal *frac)
{
	double	real;
	double	imag;

	frac->x_loop = 0;
	frac->y_loop = 0;
	while (frac->x_loop < WIDTH)
	{
		frac->y_loop = 0;
		while (frac->y_loop < HEIGHT)
		{
			real = (frac->x_loop - frac->position_x) * \
					4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
			imag = (frac->y_loop - frac->position_y) * \
					4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;
			helper(frac, imag, real);
			frac->y_loop++;
		}
		frac->x_loop++;
	}
}
