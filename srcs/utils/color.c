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