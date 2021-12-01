/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/01 14:44:54 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

t_v3f	rotate_x(t_v3f v, double alpha)
{
	return (v3f(v.x, v.y * cos(alpha) + v.z * sin(alpha),
			v.y * sin(alpha) + v.z * cos(alpha)));
}

t_v3f	rotate_y(t_v3f v, double beta)
{
	return (v3f(v.x * cos(beta) + v.z * sin(beta),
			-v.x * sin(beta) + v.z * cos(beta), v.z));
}

t_v3f	rotate_z(t_v3f v, double gamma)
{
	return (v3f(v.x * cos(gamma) - v.y * sin(gamma), v.y,
			v.x * sin(gamma) + v.y * cos(gamma)));
}
