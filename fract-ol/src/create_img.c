/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:13:51 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/24 19:22:20 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

void	ft_draw_fractals(t_data *data)
{
	if (data->launch == 1)
		ft_mandelbrot(data);
	else if (data->launch == 2)
		ft_julia(data);
	else if (data->launch == 3)
		ft_burningship(data);
}
