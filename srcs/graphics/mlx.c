#include "../../includes/glib.h"

void	init_window(t_window *window)
{
	if (!window->mlx)
	{
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
	window->win = mlx_new_window(window->mlx, width, height, title);
	if (!window->win)
	{
		free(window->win);
		perror(MLX_ERROR);
		exit(EXIT_FAILURE);
	}
}

void	init_glib(t_window *window)
{
	init_window(window);
	window->img.mlx_img = mlx_new_image(window->mlx, window->width, window->height);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp, &window->img.line_len, &window->img.endian);
	mlx_loop_hook(window->mlx, &render, window);
	mlx_key_hook(window->win, keys_hook, window);
	mlx_loop(window->mlx);
	mlx_destroy_image(window->mlx, window->img.mlx_img);
	mlx_destroy_window(window->mlx, window->win);
}
