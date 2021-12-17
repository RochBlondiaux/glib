/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:31 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:46:06 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/glib.h"

void	glib_init(t_window *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
	window->win = mlx_new_window(window->mlx, window->width,
			window->height, window->title);
	if (!window->win)
	{
		free(window->win);
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
	window->img.mlx_img = mlx_new_image(window->mlx,
			window->width, window->height);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp,
			&window->img.line_len, &window->img.endian);
}

void	glib_stop(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img.mlx_img);
	mlx_destroy_window(window->mlx, window->win);
}

void	glib_start(t_window *window)
{
	glib_init(window);
	mlx_loop(window->mlx);
	glib_stop(window);
}

void	register_loop_hook(t_window *window, int (*f)(), void *param)
{
	mlx_loop_hook(window->mlx, f, param);
}

void	register_key_hook(t_window *window, int (*f)(), void *param)
{
	mlx_key_hook(window->win, f, param);
}
