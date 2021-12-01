#include "../../includes/glib.h"

void	draw_pixel(t_window window, t_v2f v, int color)
{
	char	*pixel;
	int		i;
	t_img	*img;

	img = &window.img;
	i = img->bpp - 8;
	pixel = img->addr + (v.y * img->line_len + v.x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	draw_line(t_window window, t_v2f f, t_v2f s, int color)
{
	t_v2f	delta;
	t_v2f	sign;
	t_v2f	current;
	int		error[2];

	delta = v2f_difference(f, s);
	sign = get_sign(f, s);
	error[0] = delta.x + delta.y;
	current = f;
	while (current.x != s.x || current.y != s.y)
	{
		draw_pixel(window, current, color);
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			add_v2f(current, sign.x, 0);
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			add_v2f(current, 0, sign.y);
		}
	}
}
