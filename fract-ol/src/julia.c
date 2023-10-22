/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:53:01 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 10:41:05 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_julia_reset(t_data *data)
{
	data->iter = 0;
	data->coord.z.real = data->x_min + (data->coord.p_x + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->coord.z.imaginary = data->y_max - (data->coord.p_y + data->move_y) * (data->y_max - data->y_min) / data->small_side;
	data->coord.z.real_sq = data->coord.z.real * data->coord.z.real;
	data->coord.z.imaginary_sq = data->coord.z.imaginary * data->coord.z.imaginary;
}

void	ft_julia(t_data *data)
{
	data->coord.p_y = 0;
	while (data->coord.p_y <= WIN_HEIGHT)
	{
		data->coord.p_x = 0;
		while (data->coord.p_x <= WIN_WIDTH)
		{
			ft_julia_reset(data);
			ft_common_part(data);
			ft_pixel_put(data, data->coord.p_x, data->coord.p_y, ft_color_jul(data));
			data->coord.p_x++;
		}
		data->coord.p_y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
}
