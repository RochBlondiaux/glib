#include "../../includes/glib.h"

t_v2f	isometric_projection(t_v3f v)
{
	return (v2f((v.x - v.y) * cos(0.523599), -v.z + (v.x + v.y) * sin(0.523599)))
}
