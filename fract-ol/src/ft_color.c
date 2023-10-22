/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:58:37 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 11:26:55 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_color_man(t_data *data)
{
	double zn_abs = sqrt(data->coord.z.real_sq + data->coord.z.imaginary_sq);
    double nu = log(log(zn_abs) / log(2)) / log(2);
    double smoothed_iter = data->iter + 1 - nu;
    data->color = (int)(smoothed_iter * (data->color_man * 5) / MAX_ITER) % 256;
	return (data->color);
}

int	ft_color_jul(t_data *data)
{
	double zn_abs = sqrt(data->coord.z.real_sq + data->coord.z.imaginary_sq);
    double nu = log(log(zn_abs) / log(2)) / log(2);
    double smoothed_iter = data->iter + 1 - nu;
    int blue = (int)(smoothed_iter * (data->color_man * 5) / MAX_ITER_JUL);
    int red = 65536 * blue;
    int green = 256 * blue;
    data->color = blue + red + green;
	return (data->color);
}

int	ft_color_burn(t_data *data)
{
 	double zn_abs = sqrt(data->coord.z.real_sq + data->coord.z.imaginary_sq);
    double nu = log(log(zn_abs) / log(2)) / log(2);
    double smoothed_iter = data->iter + 1 - nu;
    data->color = (int)(smoothed_iter * (data->color_man * 5) / MAX_ITER) * 65536;
 	return (data->color);
}