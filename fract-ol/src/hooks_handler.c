/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:17:43 by recozzi           #+#    #+#             */
/*   Updated: 2023/07/02 10:20:01 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_key_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close_fractal(data);
	else if (keysym == XK_Up)
		data->move_y -= (WIN_HEIGHT / 20);
	else if (keysym == XK_Down)
		data->move_y += (WIN_HEIGHT / 20);
	else if (keysym == XK_Left)
		data->move_x -= (WIN_HEIGHT / 20);
	else if (keysym == XK_Right)
		data->move_x += (WIN_HEIGHT / 20);
	else if (keysym == XK_c)
		data->color_man += 256;
	else if (keysym == XK_r)
		ft_init_setup(data);
	ft_draw_fractals(data);
	return (0);
}

int	ft_mouse_handler(int keysym, int px, int py, t_data *data)
{
	if (keysym == 4)
		ft_zoom_in(data, px, py);
	if (keysym == 5)
		ft_zoom_out(data, px, py);
	ft_draw_fractals(data);
	return (0);
}

int	ft_close_fractal(t_data *data)
{
	ft_free_image(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}
