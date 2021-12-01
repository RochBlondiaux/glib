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
#include <stdio.h>

# include "../mlx/mlx.h"

/**
 * Constants
 */
# define MLX_ERROR	"Cannot initialize window"

/**
 * Structures
 */
typedef struct s_v2f {
	int	x;
	int	y;
}		t_v2f;

typedef struct s_v3f {
	int	x;
	int	y;
	int	z;
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
 * Graphics
 */
void	init_glib(t_window *window);

/**
 * Maths
 */

/**
 * Utils
 */
#endif