#include "fdf.h"

void	ft_x_rotate(int *y, int *z, float angl_x)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(angl_x) + *z * sin(angl_x);
	*z = -prev_y * sin(angl_x) + *z * cos(angl_x);
}

void	ft_y_rotate(int *x, int *z, float angl_y)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(angl_y) + *z * sin(angl_y);
	*z = -prev_x * sin(angl_y) + *z * cos(angl_y);
}

void	ft_z_rotate(int *x, int *y, float angl_z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(angl_z) - prev_y * sin(angl_z);
	*y = prev_x * sin(angl_z) + prev_y * cos(angl_z);
}
