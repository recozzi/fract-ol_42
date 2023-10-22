/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:30:28 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:47:43 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_zoom_in(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (py + data->move_y) * (data->y_max - data->y_min) / data->small_side;
	data->x_min = data->mouse_x - (data->mouse_x - data->x_min) * data->zoom_factor;
	data->y_min = data->mouse_y - (data->mouse_y - data->y_min) * data->zoom_factor;
	data->x_max = data->mouse_x - (data->mouse_x - data->x_max) * data->zoom_factor;
	data->y_max = data->mouse_y - (data->mouse_y - data->y_max) * data->zoom_factor;
	data->zoom *= data->zoom_factor;
}

void	ft_zoom_out(t_data *data, int px, int py)
{
	data->mouse_x = data->x_min + (px + data->move_x) * (data->x_max - data->x_min) / data->small_side;
	data->mouse_y = data->y_max - (py + data->move_y) * (data->y_max - data->y_min) / data->small_side;
	data->x_min = data->mouse_x - (data->mouse_x - data->x_min) / data->zoom_factor;
	data->y_min = data->mouse_y - (data->mouse_y - data->y_min) / data->zoom_factor;
	data->x_max = data->mouse_x - (data->mouse_x - data->x_max) / data->zoom_factor;
	data->y_max = data->mouse_y - (data->mouse_y - data->y_max) / data->zoom_factor;
	data->zoom /= data->zoom_factor;
}
