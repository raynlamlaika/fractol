/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:04:59 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/25 17:20:08 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void mouse_position(int x, int y, t_fractal *frac)
{
	frac->position_x = x;
	frac->position_y = y;
}

int key_hook_julia(int keycode, t_fractal *frac)
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
	draw_julia(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	return (0);
}
int mouse_hook_julia(int button, int x, int y, t_fractal *frac)
{
    double mouse_real, mouse_imag;

    // Convert mouse position to fractal coordinates
    mouse_real = (x - frac->position_x) * 4.0 / (WIDTH * frac->zoom) + frac->offsetreal;
    mouse_imag = (y - frac->position_y) * 4.0 / (HEIGHT * frac->zoom) + frac->offsetimag;

    if (button == 4) // Scroll up (zoom in)
    {
        frac->zoom *= 1.1; // Increase zoom level
        // Adjust offsets to keep the cursor position fixed
        frac->offsetreal += (mouse_real - frac->offsetreal) * (1 - 1 / 1.1);
        frac->offsetimag += (mouse_imag - frac->offsetimag) * (1 - 1 / 1.1);
    }
    else if (button == 5) // Scroll down (zoom out)
    {
        frac->zoom /= 1.1; // Decrease zoom level
        // Adjust offsets to keep the cursor position fixed
        frac->offsetreal += (mouse_real - frac->offsetreal) * (1 - 1.1);
        frac->offsetimag += (mouse_imag - frac->offsetimag) * (1 - 1.1);
    }

    // Redraw the fractal
    draw_julia(frac);
    mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
    return (0);
}

static int	init_julia(t_fractal *frac, char**av)
{
	init_fractal(frac);
	frac->julia_c_imag = ft_atof(av[2]);
	frac->julia_c_real = ft_atof(av[3]);
	frac->position_y =0 ;
	frac->position_x = 0;
	draw_julia(frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_mouse_hook(frac->wind, mouse_hook_julia, frac);
	mlx_hook(frac->wind, 2, 0, key_hook_julia, frac);
	mlx_put_image_to_window(frac->init, frac->wind, frac->img, 0, 0);
	mlx_loop(frac->init);
	mlx_destroy_image(frac->init, frac->img);
	mlx_destroy_window(frac->init, frac->wind);
	return (1);
}

void	check_pass_julia(int ac,char **av, t_fractal *frac)
{
	if (ft_strncmp("Julia", av[1], 6) == 0 && ft_atof(av[2]) && ft_atof(av[3]))
		init_julia(frac, av);
	mlx_loop(frac->init);
}
