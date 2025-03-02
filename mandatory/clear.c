/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:57:03 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/02 21:57:32 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int clearr(t_fractal *frac)
{
	if (frac->init && frac->wind)
		mlx_destroy_window(frac->init, frac->wind);
	exit(1);
	return (1);
}
