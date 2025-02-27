/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:58:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/27 20:42:53 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define TITLE "Fractal"
# define WIDTH 1200
# define HEIGHT 1200
# define MAX_ITER 100
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PRESS_EVENT 2

typedef struct s_fractal
{
	void	*init;
	void	*wind;
	void	*img;
	char	*addr;
	int		bits_for_pixel;
	int		line_length;
	int		endian;
	int		interation;
	double	zoom;
	double	offsetreal;
	double	offsetimag;
	int		color;
	double	julia_c_imag;
	double	julia_c_real;
	double	position_x;
	double	position_y;
	int		x_loop;
	int		y_loop;
}			t_fractal;

int		init_fractal(t_fractal *fractal);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	my_mlx_pixel_put(t_fractal *mlx);
void	draw_mlbro(t_fractal *frac);
void	finishing(t_fractal *frac);
void	check_pass_julia(char**av, t_fractal *frac);
size_t	ft_strlen(char *str);
double	ft_atof(char *tfloat);
// int		key_hook(int keycode, t_fractal *frac);
// int		mouse_hook(int button, int x, int y, t_fractal *frac);
int		init_julia(t_fractal *frac, char**av);
void	draw_julia(t_fractal *frac);
int		mouse_hook_julia(int button, int x, int y, t_fractal *frac);
int		key_hook_julia(int keycode, t_fractal *frac);
void	mouse_position(int x, int y, t_fractal *frac);

#endif