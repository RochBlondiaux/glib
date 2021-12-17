/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:57 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:44:58 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

int	convert_rgba(int a, int r, int g, int b)
{
	return ((255 - a) << 24 | r << 16 | g << 8 | b);
}

int	rgb(int r, int g, int b)
{
	return (convert_rgba(255, r, g, b));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_v2f current, t_v2f start, t_v2f end, t_v2f delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
