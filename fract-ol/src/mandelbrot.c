/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:17:45 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:44:39 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_mandelbrot_reset(t_data *data)
{
	data->iter = 0;
	data->coord.z.real = 0;
	data->coord.z.imaginary = 0;
	data->coord.c.real = data->x_min + (data->coord.p_x + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->coord.c.imaginary = data->y_max - (data->coord.p_y + data->move_y) * (data->y_max - data->y_min) / data->small_side;
	data->coord.z.real_sq = 0;
	data->coord.z.imaginary_sq = 0;
}

void	ft_common_part(t_data *data)
{
	while (data->coord.z.real_sq + data->coord.z.imaginary_sq < 4 && data->iter < MAX_ITER)
	{
		data->coord.z.imaginary = 2 * data->coord.z.real * data->coord.z.imaginary - data->coord.c.imaginary;
		data->coord.z.real = data->coord.z.real_sq - data->coord.z.imaginary_sq + data->coord.c.real;
		data->coord.z.real_sq = data->coord.z.real * data->coord.z.real;
		data->coord.z.imaginary_sq = data->coord.z.imaginary * data->coord.z.imaginary;
		data->iter++;
	}
}

void	ft_mandelbrot(t_data *data)
{
	data->coord.p_y = 0;
	while (data->coord.p_y <= WIN_HEIGHT)
	{
		data->coord.p_x = 0;
		while (data->coord.p_x <= WIN_WIDTH)
		{
			ft_mandelbrot_reset(data);
			ft_common_part(data);
			ft_pixel_put(data, data->coord.p_x, data->coord.p_y, ft_color_man(data));
			data->coord.p_x++;
		}
		data->coord.p_y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}
