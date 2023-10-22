/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:19:50 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:46:32 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_invalid_args(void)
{
	ft_printf("\nAvailable fractals: Mandelbrot, Julia and Burningship\n\n");
	ft_printf("To launch Mandelbrot: ./fractol mandelbrot\n\n");
	ft_printf("To launch Burningship: ./fractol burningship\n\n");
	ft_printf("To launch Julia: ./fractol julia x y ");
	ft_printf("(x and y are complex numbers ");
	ft_printf("between -2.000 and 2.000 not included)\n\n");
}

bool	ft_julia_args(t_data *data, char **argv)
{
	data->coord.c.real = ft_atof(*(argv + 2));
	data->coord.c.imaginary = ft_atof(*(argv + 3));
	if (data->coord.c.real > -2 && data->coord.c.real < 2 && data->coord.c.imaginary > -2 && data->coord.c.imaginary < 2)
		return (true);
	return (false);
}

bool	ft_check_args(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (ft_strcmp(*(argv + 1), "mandelbrot") == 0)
		{
			data->launch = 1;
			return (true);
		}
		else if (ft_strcmp(*(argv + 1), "burningship") == 0)
		{
			data->launch = 3;
			return (true);
		}
	}
	else if (argc == 4)
	{
		if (ft_strcmp(*(argv + 1), "julia") == 0 && ft_julia_args(data, argv) == true)
		{
			data->launch = 2;
			return (true);
		}
	}
	return (false);
}
