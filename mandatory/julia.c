/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:04:59 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 06:13:19 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook_julia(int keycode, t_fractal *frac)
{
	if (keycode == 49)
		frac->color_shift = (rand() % 0xFFFFFF);
	else if (keycode == 53)
		exit(0);
	draw_julia(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

int	mouse_hook_julia(int button, int x, int y, t_fractal *frac)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = (x - frac->position_x) * 4.0 / (WIDTH * frac->zoom);
	mouse_imag = (y - frac->position_y) * 4.0 / (HEIGHT * frac->zoom);
	if (button == 4)
		frac->zoom *= 1.1;
	else if (button == 5)
		frac->zoom /= 1.1;
	draw_julia(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

int	init_julia(t_fractal *frac, char**av)
{
	frac->julia_c_imag = ft_atof(av[2]);
	frac->julia_c_real = ft_atof(av[3]);
	init_fractal(frac);
	draw_julia(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook_julia, frac);
	mlx_key_hook(frac->wind, key_hook_julia, frac);
	mlx_hook(frac->wind, 17, 0, &clearr, frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_loop(frac->init);
	mlx_destroy_image(frac->init, frac->img);
	mlx_destroy_window(frac->init, frac->wind);
	return (1);
}

void	check_pass_julia(char **av, t_fractal *frac)
{
	if (ft_strncmp("Julia", av[1], 6) == 0)
		init_julia(frac, av);
	else
	{
		free(frac);
		write(2, "arrgmment not valid bro !!!\n", 29);
		exit(1);
	}
	mlx_loop(frac->init);
}
