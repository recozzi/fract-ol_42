/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:15 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/15 11:03:34 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (ft_check_args(argc, argv, data) == false)
	{
		ft_invalid_args();
		free(data);
		exit(0);
	}
	ft_init(data);
	ft_init_setup(data);
	mlx_hook(data->win_ptr, 2, (1L << 0), &ft_key_handler, data);
	mlx_mouse_hook(data->win_ptr, &ft_mouse_handler, data);
	mlx_hook(data->win_ptr, 17, 0, &ft_close_fractal, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
