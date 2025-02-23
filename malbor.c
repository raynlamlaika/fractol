/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malbor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:08:41 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/23 13:28:24 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	helper(t_fractal *frac, int x, int y, double imag, double real)
{
	int		iter;
	double	newimg;
	double	newreal;
	double	tmp;

	iter = 0;
	newreal = 0.0;
	newimg = 0.0;
	while ((newimg * newimg + newreal * newreal) <= 2 && max_iter > iter)
	{
		tmp = newreal * newreal - newimg * newimg + real;
		newimg = 2 * newreal * newimg + imag;
		newreal = tmp;
		iter++;
	}
	if (iter == max_iter)
		frac->color = 0x011BB11;
	else
		frac->color = (iter * 255 / max_iter) * 0x010100;
	my_mlx_pixel_put(frac , y, x, frac->color);
}

void	draw_mlbro(t_fractal *frac)
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
			real = (x - WIDTH / 2.0) * 4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
			imag = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;
			helper(frac, x, y, real, imag);
			y++;
		}
		x++;
	}
}
