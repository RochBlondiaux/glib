#include "../../includes/glib.h"

t_v2f	v2f_difference(t_v2f f, t_v2f s)
{
	return (v2f(abs(s.x - f.x), -abs(s.y - f.y)));
}

t_v2f	get_sign(t_v2f f, t_v2f s)
{
	t_v2f	sign;

	if (f.x < s.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (f.y < s.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

double	deg_to_rad(int degree)
{
	return (degree * 3.14159265F / 180.0F);
}
