#include "../../includes/glib.h"

t_v2f	isometric_projection(t_v3f v)
{
	return (v2f((v.x - v.y) * cos(0.523599),
			-v.z + (v.x + v.y) * sin(0.523599)));
}

t_v2f	parallel_projection(t_v3f v, int angle)
{
	return (v2f(v.x + cos(deg_to_rad(angle)) * v.z,
			v.y + sin(deg_to_rad(angle)) * v.z));
}