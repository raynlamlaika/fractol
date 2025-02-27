/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:26:58 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/27 10:00:04 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_fractal(t_fractal *fractal)
{
	fractal->init = mlx_init();
	if (!fractal->init)
		return (write(2, "the init of the mlx are failed\n", 32), exit(1), 0);
	fractal->wind = mlx_new_window(fractal->init, WIDTH, HEIGHT, TITLE);
	if (!fractal->wind)
		return (write(2, "window of the mlx are failed\n", 29), \
				free(fractal->init), exit(1), 0);
	fractal->img = mlx_new_image(fractal->init, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		write(2, "faild in the img creation\n", 26);
		free(fractal->init);
		return (exit(1), 0);
	}
	fractal->addr = mlx_get_data_addr(fractal->img, \
		&fractal->bits_for_pixel, &fractal->line_length, &fractal->endian);
	if (!fractal->addr)
		exit(1);
	fractal->zoom = 1.03;
	fractal->offsetreal = -2.0;
	fractal->offsetimag = -2.0;
	return (1);
}
