/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:58:36 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 06:13:44 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_hook_mandel(int keycode, t_fractal *frac)
{
	if (keycode == 49)
		frac->color_shift = (rand() % 0xFFFFFF);
	if (keycode == KEY_DOWN)
		frac->offsetimag += 0.1 / frac->zoom;
	else if (keycode == KEY_UP)
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

int	mouse_hook_mandel(int button, int x, int y, t_fractal *frac)
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

void	my_mlx_pixel_put(t_fractal *fract)
{
	char	*pixel;

	if (fract->x_loop >= 0 && fract->x_loop < WIDTH && \
		fract->y_loop >= 0 && fract->y_loop < HEIGHT)
	{
		pixel = fract->addr + (fract->y_loop * \
		fract->line_length + fract->x_loop * (fract->bits_for_pixel / 8));
		*(unsigned int *)pixel = fract->color;
	}
}

void	draw_mandelbort(t_fractal *frac)
{
	init_fractal(frac);
	frac->position_y = -2;
	frac->position_x = 2;
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook_mandel, frac);
	mlx_key_hook(frac->wind, key_hook_mandel, frac);
	mlx_hook(frac->wind, 17, 0, &clearr, frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_loop(frac->init);
	mlx_destroy_image(frac->init, frac->img);
	mlx_destroy_window(frac->init, frac->wind);
}

int	main(int ac, char**av)
{
	t_fractal	*frac;

	frac = malloc(sizeof(t_fractal));
	if (!frac)
		return (write(2, "Allocation error\n", 18), 1);
	frac->color_shift = 0x010101;
	if (ac == 2)
	{
		if (ft_strncmp("Mandelbrot", av[1], 11) == 0)
			draw_mandelbort(frac);
		else if (ft_strncmp("Burning_ship", av[1], 13) == 0)
			draw_burning(frac);
		else
			return (write(2, "Invalid argument\n", 18), free(frac), 0);
	}
	if (ac == 4)
		check_pass_julia(av, frac);
	else
		return (free(frac), exit(1), 0);
	finishing(frac);
	return (0);
}
