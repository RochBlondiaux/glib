/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:23 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:45:24 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

t_v2f	v2f(int x, int y)
{
	t_v2f	v;

	v.x = x;
	v.y = y;
	v.color = rgb(236, 240, 241);
	return (v);
}

t_v2f	add_v2f(t_v2f v, int x, int y)
{
	return (v2f(v.x + x, v.y + y));
}

t_v2f	sub_v2f(t_v2f v, int x, int y)
{
	return (v2f(v.x - x, v.y - y));
}

t_v2f	mul_v2f(t_v2f v, int x, int y)
{
	return (v2f(v.x * x, v.x * y));
}

t_v2f	div_v2f(t_v2f v, int x, int y)
{
	return (v2f(v.x / x, v.y + y));
}
