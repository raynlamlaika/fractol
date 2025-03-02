/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:16:09 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/28 14:38:03 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook_burning(int keycode, t_fractal *frac)
{
	if (keycode == KEY_LEFT)
		frac->offsetreal -= 0.1 / frac->zoom;
	else if (keycode == KEY_RIGHT)
		frac->offsetreal += 0.1 / frac->zoom;
	else if (keycode == KEY_UP)
		frac->offsetimag -= 0.1 / frac->zoom;
	else if (keycode == KEY_DOWN)
		frac->offsetimag += 0.1 / frac->zoom;
	else if (keycode == 53)
		exit(0);
	burning_ship(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

int	mouse_hook_burning(int button, int x, int y, t_fractal *frac)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - frac->position_x) * \
				4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
	mouse_imag = (y - frac->position_y) * \
				4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;
	if (button == 4)
	{
		frac->zoom *= 1.1;
		frac->offsetreal += (mouse_real - frac->offsetreal) * \
							(1 - 1 / 1.1);
		frac->offsetimag += (mouse_imag - frac->offsetimag) * \
							(1 - 1 / 1.1);
	}
	else if (button == 5)
	{
		frac->zoom /= 1.1;
		frac->offsetreal += (mouse_real - frac->offsetreal) \
							* (1 - 1.1);
		frac->offsetimag += (mouse_imag - frac->offsetimag) * (1 - 1.1);
	}
	burning_ship(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

void	draw_burning(t_fractal *frac)
{
	init_fractal(frac);
	frac->position_y = -2;
	frac->position_x = 2;
	burning_ship(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook_burning, frac);
	mlx_hook(frac->wind, 2, 0, key_hook_burning, frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_loop(frac->init);
	mlx_destroy_image(frac->init, frac->img);
	mlx_destroy_window(frac->init, frac->wind);
}
