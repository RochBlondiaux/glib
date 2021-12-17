/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:32 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 10:53:23 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

void	draw_pixel(t_window *window, t_v2f v, int color)
{
	int		i;
	t_img	*img;

	img = &window->img;
	if (!(v.x > 0 && v.x < window->width && v.y > 0 && v.y < window->height))
		return ;
	i = (v.x * img->bpp / 8) + (v.y * img->line_len);
	img->addr[i] = color;
	img->addr[++i] = color >> 8;
	img->addr[++i] = color >> 16;
}

void	draw_line(t_window *window, t_v2f f, t_v2f s, int color)
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
			current = add_v2f(current, sign.x, 0);
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current = add_v2f(current, 0, sign.y);
		}
	}
}

void	draw_gradient_line(t_window *window, t_v2f f, t_v2f s)
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
		draw_pixel(window, current, get_color(current, f, s, delta));
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			current = add_v2f(current, sign.x, 0);
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current = add_v2f(current, 0, sign.y);
		}
	}
}
