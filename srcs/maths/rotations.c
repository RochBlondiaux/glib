/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:44:53 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 10:19:57 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/glib.h"

void	rotate_x(t_v3f *v, double alpha)
{
	int	previous_y;

	previous_y = v->y;
	v->y = previous_y * cos(alpha) + v->z * sin(alpha);
	v->z = -previous_y * sin(alpha) + v->z * cos(alpha);
}

void	rotate_y(t_v3f *v, double beta)
{
	int	previous_x;

	previous_x = v->x;
	v->x = previous_x * cos(beta) + v->z * sin(beta);
	v->z = -previous_x * sin(beta) + v->z * cos(beta);
}

void	rotate_z(t_v3f *v, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = v->x;
	previous_y = v->y;
	v->x = previous_x * cos(gamma) - previous_y * sin(gamma);
	v->y = previous_x * sin(gamma) + previous_y * cos(gamma);
}
