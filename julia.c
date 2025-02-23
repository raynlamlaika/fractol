/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:04:59 by rlamlaik          #+#    #+#             */
/*   Updated: 2025/02/23 15:29:11 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static double  check(char*tfloat)
{
    double  result;
    int     i;

    if (!tfloat)
        return (exit(1), 0);
    i = 0;
    while((tfloat[i] <= '9' && tfloat[i] >=  '0')|| tfloat[i] == '.')
    {
        i++;
    }

    return (result);
}
void	check_pass_julia(int ac,char **av, t_fractal *frac)
{
    if (check(av[2]) && check(av[3]))
		init_fractal(frac);
    mlx_loop(frac->init);

}
// int main(int ac, char**av)
// {
//     check_pass_julia(ac, av);
//     return 0;
// }