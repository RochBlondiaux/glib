#include "../../includes/glib.h"

t_v3f	v3f(int x, int y, int z)
{
	t_v3f	v;

	v.x = x;
	v.y = y;
	v.z = z;
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
