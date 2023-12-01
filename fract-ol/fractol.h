/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:26:21 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 11:29:42 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# define WIN_WIDTH 950
# define WIN_HEIGHT	950
# define MLX_ERROR -1
# define MAX_ITER 200
# define MAX_ITER_JUL 300

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	real;
	double	imaginary;
	double	real_sq;
	double	imaginary_sq;
}	t_complex;

typedef struct s_coord
{
	int			p_x;
	int			p_y;
	t_complex	z;
	t_complex	c;
}	t_coord;

typedef struct s_data
{	
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	double		move_x;
	double		move_y;
	int			launch;
	t_coord		coord;
	int			color;
	int			color_man;
	int			iter;
	double		x_min;
	double		x_max;
	int			small_side;
	double		y_min;
	double		y_max;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	double		zoom_factor;
}	t_data;

int		ft_init(t_data *data);
int		ft_key_handler(int keysym, t_data *data);
int		ft_mouse_handler(int keysym, int px, int py, t_data *data);
int		ft_close_fractal(t_data *data);
int		ft_color_man(t_data *data);
int		ft_color_jul(t_data *data);
int		ft_color_burn(t_data *data);

void	ft_invalid_args(void);
void	ft_init_setup(t_data *data);
void	ft_draw_fractals(t_data *data);
void	ft_pixel_put(t_data *data, int x, int y, int color);
void	ft_mandelbrot(t_data *data);
void	ft_mandelbrot_reset(t_data *data);
void	ft_julia_reset(t_data *data);
void	ft_julia(t_data *data);
void	ft_zoom_in(t_data *data, int px, int py);
void	ft_zoom_out(t_data *data, int px, int py);
void	ft_burningship(t_data *data);
void	ft_free_image(t_data *data);
void	ft_common_part(t_data *data);

bool	ft_check_args(int argc, char **argv, t_data *data);
bool	ft_julia_args(t_data *data, char **argv);

#endif
