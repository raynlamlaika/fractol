/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:58:36 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/20 15:07:25 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char**av)
{
	t_fractal   mlx;

	mlx.init = mlx_init();
	if (!mlx.init)
		return (write(2, "problem in init the mlx pointer\n",32), 0);
	mlx.wind = mlx_new_window(mlx.init, 1000, 700, "Fractol");
	if(!mlx.wind)
		return (write(2, "problm in oping the new window\n", 31), free(mlx.init) ,0);
	mlx.img = mlx_new_image(mlx.init,900, 300);
    if (!mlx.img)
    {
        fprintf(stderr, "Error: Image creation failed.\n");
        mlx_destroy_window(mlx.init, mlx.wind);
        free(mlx.init);
        return (0);
    }
	// mlx.adrr= mlx_get_data_addr(mlx.img, );
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_for_pixel, &mlx.line_length, &mlx.endian);
	
	mlx_loop(mlx.init);
	mlx_destroy_image(mlx.init, mlx.img);
    mlx_destroy_window(mlx.init, mlx.wind);
    mlx_destroy_display(mlx.init);
	return (0);
}