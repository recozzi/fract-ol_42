/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:35:44 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:31:06 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_burning_ship(t_data *data)
{
	while (data->coord.z.real_sq + data->coord.z.imaginary_sq < 4 && data->iter < MAX_ITER)
	{
		data->coord.z.imaginary = fabsl(2 * data->coord.z.real * data->coord.z.imaginary - data->coord.c.imaginary);
		data->coord.z.real = fabsl(data->coord.z.real_sq - data->coord.z.imaginary_sq + data->coord.c.real);
		data->coord.z.real_sq = data->coord.z.real * data->coord.z.real;
		data->coord.z.imaginary_sq = data->coord.z.imaginary * data->coord.z.imaginary;
		data->iter++;
	}
}

void	ft_burningship(t_data *data)
{
	data->coord.p_y = 0;
	while (data->coord.p_y <= WIN_HEIGHT)
	{
		data->coord.p_x = 0;
		while (data->coord.p_x <= WIN_WIDTH)
		{
			ft_mandelbrot_reset(data);
			ft_burning_ship(data);
			ft_pixel_put(data, data->coord.p_x, data->coord.p_y, ft_color_burn(data));
			data->coord.p_x++;
		}
		data->coord.p_y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}
