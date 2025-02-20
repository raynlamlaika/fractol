/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:58:31 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/20 15:00:36 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_fractal
{
	void*	init;
	void*	wind;
	void*	img;
	char*	addr;
	int		bits_for_pixel;
	int		line_length;
	int		endian;
}			t_fractal;



#endif
