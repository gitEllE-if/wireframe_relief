#include "fdf.h"
#include "fdf_projection.h"

void	ft_iso(int *x, int *y, float z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ISO_ANGL);
	*y = -z + (prev_x + prev_y) * sin(ISO_ANGL);
}

void	ft_spher(int *x, int *y, float lon, float lat)
{
	int		prev_x;
	int		prev_y;
	float	sx;
	float	sy;
	float	sz;

	prev_x = *x;
	prev_y = *y;
	lon = (prev_x / 2) * M_PI / CONST1;
	lat = (prev_y * M_PI / 2) / CONST1;
	sx = CONST1 * cos(lat) * cos(lon);
	sy = CONST1 * cos(lat) * sin(lon);
	sz = CONST1 * sin(lat);
	lon = CONST2 * (atan2(sqrt(sx * sx + sy * sy), sy)) / (192.5 * M_PI / 180);
	*x = lon * cos(atan2(sz, sx)) + CONST1;
	*y = lon * sin(atan2(sz, sx)) + CONST1;
}

void	ft_custom(int *x, int *y, int z, t_fdf *fdf)
{
	int		prev_x;
	int		prev_y;
	float	k;

	fdf->data++;
	k = (float)fdf->map->height / (float)fdf->data;
	prev_x = *x;
	prev_y = *y;
	*x = ((prev_x - 0.5 * prev_y) * cos(0.7)) / k;
	*y = (-z + (0.5 * prev_y) * sin(0.7)) / k;
}

t_point	ft_projection(t_point p, t_fdf *fdf)
{
	fdf->data = p.y;
	p.x *= fdf->view->zoom;
	p.y *= fdf->view->zoom;
	p.z *= fdf->view->zoom + fdf->view->z_deep;
	p.x -= (fdf->map->width * fdf->view->zoom) / 2;
	p.y -= (fdf->map->height * fdf->view->zoom) / 2;
	ft_x_rotate(&p.y, &p.z, fdf->view->angl_x);
	ft_y_rotate(&p.x, &p.z, fdf->view->angl_y);
	ft_z_rotate(&p.x, &p.y, fdf->view->angl_z);
	if (fdf->view->projection == iso)
		ft_iso(&p.x, &p.y, p.z);
	if (fdf->view->projection == persp)
		ft_custom(&p.x, &p.y, p.z, fdf);
	if (fdf->view->projection == spher)
	{
		ft_spher(&p.x, &p.y, 0, 0);
		p.x -= 800;
		p.y -= 300;
	}
	p.x += WIDTH / 2 + fdf->view->x_offset;
	p.y += HEIGHT / 2 + fdf->view->y_offset;
	return (p);
}
