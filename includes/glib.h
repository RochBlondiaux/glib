/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glib.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:46:12 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:46:15 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLIB_H
# define GLIB_H

/**
 * Libraries
 */
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# include "../mlx/mlx.h"

/**
 * Constants
 */
# define MLX_ERROR	"Cannot initialize window"
# define UNIQ_BPP 4

/**
 * Structures
 */
typedef struct s_v2f {
	int	x;
	int	y;
	int	color;
}		t_v2f;

typedef struct s_v3f {
	int	x;
	int	y;
	int	z;
	int	color;
}		t_v3f;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_window {
	void	*mlx;
	void	*win;
	char	*title;
	int		width;
	int		height;
	t_img	img;
}			t_window;

/**
 * 2D Vectors
 */
t_v2f	v2f(int x, int y);
t_v2f	add_v2f(t_v2f v, int x, int y);
t_v2f	sub_v2f(t_v2f v, int x, int y);
t_v2f	mul_v2f(t_v2f v, int x, int y);
t_v2f	div_v2f(t_v2f v, int x, int y);

/**
 * 3D Vectors
 */
t_v3f	v3f(int x, int y, int z);
t_v3f	add_v3f(t_v3f v, int x, int y, int z);
t_v3f	sub_v3f(t_v3f v, int x, int y, int z);
t_v3f	mul_v3f(t_v3f v, int x, int y, int z);
t_v3f	div_v3f(t_v3f v, int x, int y, int z);

/**
 * System
 */
void	glib_init(t_window *window);
void	glib_start(t_window *window);
void	glib_stop(t_window *window);
void	register_loop_hook(t_window *window, int (*f)(), void *param);
void	register_key_hook(t_window *window, int (*f)(), void *param);

/**
 * Graphics
 */
void	draw_pixel(t_window *window, t_v2f v, int color);
void	draw_line(t_window *window, t_v2f f, t_v2f s, int color);
void	draw_gradient_line(t_window *window, t_v2f f, t_v2f s);

/**
 * Projections
 */
t_v2f	isometric_projection(t_v3f v);
t_v2f	parallel_projection(t_v3f v, int angle);

/**
 * Maths
 */
t_v2f	v2f_difference(t_v2f f, t_v2f s);
t_v2f	get_sign(t_v2f f, t_v2f s);
double	deg_to_rad(int degree);
void	rotate_x(t_v3f *v, double alpha);
void	rotate_y(t_v3f *v, double beta);
void	rotate_z(t_v3f *v, double gamma);

/**
 * Utils
 */
int		convert_rgba(int a, int r, int g, int b);
int		rgb(int r, int g, int b);
double	percent(int start, int end, int current);
int		get_light(int start, int end, double percentage);
int		get_color(t_v2f current, t_v2f start, t_v2f end, t_v2f delta);

#endif