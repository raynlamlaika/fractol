/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:34:22 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/26 17:06:46 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_float(char *helper, int i)
{
	if (helper[i] == '-' || helper[i] == '+')
	{
		i++;
		if (helper[i] < '0' || helper[i] > '9')
			return (write(2, "argument not valid\n", 19), exit(1), 0);
	}
	return (1);
}

static int	atof_helper(char*tfloat)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (!tfloat)
		return (write(2, "argument not valid\n", 19), exit(1), 0);
	if (tfloat[0] == '.' || tfloat[ft_strlen(tfloat) - 1] == '.')
		return (write(2, "argument not valid\n", 19), exit(1), 0);
	while (tfloat[i])
	{
		if ((tfloat[i] >= '0' && tfloat[i] <= '9') || tfloat[i] == '.' || \
			tfloat[i] == '-' || tfloat[i] == '+')
		{
			if (tfloat[i] == '.')
				y++;
		}
		else
			return (write(2, "argument not valid\n", 19), exit(1), 0);
		if (y > 1)
			return (write(2, "argument not valid\n", 19), exit(1), 0);
		i++;
	}
	return (1);
}

double	ft_atof(char *tfloat)
{
	double	result;
	int		i;
	int		sign;
	double	fraction;

	fraction = 1.0;
	sign = 1;
	result = 0.0;
	i = 0;
	atof_helper(tfloat);
	if ((tfloat[i] == '-' || tfloat[i] == '+') && check_float(tfloat, i))
		if (tfloat[i++] == '-')
			sign = -1;
	while (tfloat[i] >= '0' && tfloat[i] <= '9')
		result = result * 10.0 + (tfloat[i++] - '0');
	if (tfloat[i++] == '.')
	{
		while (tfloat[i] >= '0' && tfloat[i] <= '9')
		{
			fraction /= 10.0;
			result += (tfloat[i] - '0') * fraction;
			i++;
		}
	}
	return (result * sign);
}
