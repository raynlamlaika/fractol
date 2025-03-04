/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:48:18 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/03/04 05:30:34 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	clearr(t_fractal *frac)
{
	if (frac->init && frac->wind)
		mlx_destroy_window(frac->init, frac->wind);
	exit(1);
	return (1);
}
