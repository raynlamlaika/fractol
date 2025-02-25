/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:58:36 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/25 16:25:40 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int keycode, t_fractal *frac)
{
	if (keycode == KEY_PLUS)
		frac->interation += 10;
	else if(keycode == KEY_MINUS)
		frac->interation -= 10;
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
int	mouse_hook(int button, int x, int y, t_fractal *frac)
{
	if (button == 4) // scroll up
		frac->zoom *= 1.1;
	else if (button == 5) // scroll down
		frac->zoom /= 1.1;
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_fractal *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = mlx->addr + (y * mlx->line_length + x * (mlx->bits_for_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw_Mandelbort(t_fractal *frac)
{
	init_fractal(frac);
	draw_mlbro(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook, frac);
	mlx_hook(frac->wind, 2, 0, key_hook, frac);
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
	if (ac == 2)
	{
		if(ft_strncmp("Mandelbrot", av[1], 11) == 0)
			draw_Mandelbort(frac);
		else
			return (write(2, "Invalid argument\n", 18), free(frac), 0);
	}
	if (ac == 4)
		check_pass_julia(ac, av, frac);
	finishing(frac);
	return (0);
}


