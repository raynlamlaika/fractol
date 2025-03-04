/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buring_ship_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:13:40 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 06:16:55 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook_borning(int keycode, t_fractal *frac)
{
	if (keycode == KEY_UP)
		frac->offsetimag += 0.1 / frac->zoom;
	else if (keycode == KEY_DOWN)
		frac->offsetimag -= 0.1 / frac->zoom;
	else if (keycode == KEY_LEFT)
		frac->offsetreal -= 0.1 / frac->zoom;
	else if (keycode == KEY_RIGHT)
		frac->offsetreal += 0.1 / frac->zoom;
	else if (keycode == 53)
		exit(0);
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

int	mouse_hook_borning(int button, int x, int y, t_fractal *frac)
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
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

void	draw_borning(t_fractal *frac)
{
	init_fractal(frac);
	frac->position_y = -2;
	frac->position_x = 2;
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook_borning, frac);
	mlx_key_hook(frac->wind, key_hook_borning, frac);
	mlx_hook(frac->wind, 17, 0, &clearr, frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_loop(frac->init);
	mlx_destroy_image(frac->init, frac->img);
	mlx_destroy_window(frac->init, frac->wind);
}

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
		newimg = fabs(2 * newreal * newimg + imag);
		newreal = tmp;
		iter++;
	}
	if (iter == frac->interation)
		frac->color = 0x000000;
	else
		frac->color = (iter * 255 / frac->interation) * frac->color_shift;
	my_mlx_pixel_put(frac);
}

void	burning_ship(t_fractal *frac)
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
