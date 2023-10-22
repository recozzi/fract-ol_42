/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:01:32 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:45:41 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fract-ol");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}

void	ft_free_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
}

int	ft_small_side(t_data *data)
{
	if (WIN_HEIGHT > 0 && WIN_WIDTH > 0)
	{
		if (WIN_HEIGHT < WIN_WIDTH)
			return (WIN_HEIGHT);
		else
			return (WIN_WIDTH);
	}
	ft_free_image(data);
	ft_putstr_fd("Invalid window size. Please use nbr > 0.", 2);
	exit(1);
}

void	ft_init_setup(t_data *data)
{
	data->move_x = 0;
	data->move_y = 0;
	data->iter = 0;
	data->color = 0;
	data->color_man = 0x0000FF;
	data->x_min = -2;
	data->x_max = 2;
	data->y_min = -2;
	data->y_max = 2;
	data->small_side = ft_small_side(data);
	data->zoom = 1;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->zoom_factor = 0.9;
	ft_draw_fractals(data);
}
