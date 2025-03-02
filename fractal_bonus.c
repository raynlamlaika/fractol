/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:04:50 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/28 13:27:15 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_buring_ship(t_fractal *frac)
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
			imag = fabs((frac->y_loop - frac->position_y) * \
					4.0 / (HEIGHT * frac->zoom) + frac->offsetimag);
			helper(frac, imag, real);
			frac->y_loop++;
		}
		frac->x_loop++;
	}
}
