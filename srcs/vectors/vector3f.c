/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:45:28 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:45:29 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

t_v3f	v3f(int x, int y, int z)
{
	t_v3f	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.color = -1;
	return (v);
}

t_v3f	add_v3f(t_v3f v, int x, int y, int z)
{
	return (v3f(v.x + x, v.y + y, v.z + z));
}

t_v3f	sub_v3f(t_v3f v, int x, int y, int z)
{
	return (v3f(v.x - x, v.y - y, v.z - z));
}

t_v3f	mul_v3f(t_v3f v, int x, int y, int z)
{
	return (v3f(v.x * x, v.y * y, v.z * z));
}

t_v3f	div_v3f(t_v3f v, int x, int y, int z)
{
	return (v3f(v.x / x, v.y / y, v.z / z));
}
