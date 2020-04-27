#include "fdf.h"

static void	ft_set_point(int *error, int *delta, int *sign, t_point *p)
{
	if ((error[1] = error[0] * 2) > -delta[1])
	{
		error[0] -= delta[1];
		p->x += sign[0];
	}
	if (error[1] < delta[0])
	{
		error[0] += delta[0];
		p->y += sign[1];
	}
}

void		ft_bresenham_line(t_point p1, t_point p2, t_fdf *fdf)
{
	int		delta[2];
	int		sign[2];
	int		error[2];
	t_point	p;
	t_point	p_tmp;

	delta[0] = ABS(p2.x - p1.x);
	delta[1] = ABS(p2.y - p1.y);
	sign[0] = p1.x < p2.x ? 1 : -1;
	sign[1] = p1.y < p2.y ? 1 : -1;
	error[0] = delta[0] - delta[1];
	p = p1;
	while (p.x != p2.x || p.y != p2.y)
	{
		p_tmp = p;
		p_tmp.z = ft_set_z(p, p1, p2, delta);
		p_tmp.color = ft_set_gradnt(p, p1, p2, delta);
		ft_set_pixel(p_tmp, fdf);
		if (fdf->state & FDF_FAT)
		{
			p_tmp.x++;
			ft_set_pixel(p_tmp, fdf);
		}
		ft_set_point(error, delta, sign, &p);
	}
}

t_point		*ft_interpltn(t_point p1, t_point p2, int i, int size)
{
	int		delta[2];
	int		sign[2];
	int		error[2];
	t_point	p;
	t_point	*p_arr;

	delta[0] = ABS(p2.x - p1.x);
	delta[1] = ABS(p2.y - p1.y);
	sign[0] = p1.x < p2.x ? 1 : -1;
	sign[1] = p1.y < p2.y ? 1 : -1;
	error[0] = delta[0] - delta[1];
	size = delta[0] > delta[1] ? delta[0] : delta[1];
	p_arr = (t_point*)malloc(sizeof(t_point) * (size + 2));
	p_arr[0] = p1;
	p_arr[0].color = size;
	p = p1;
	while (p.x != p2.x || p.y != p2.y)
	{
		p.color = ft_set_gradnt(p, p1, p2, delta);
		p.z = ft_set_z(p, p1, p2, delta);
		p_arr[i++] = p;
		ft_set_point(error, delta, sign, &p);
	}
	return (p_arr);
}

void		ft_interp_ar(t_point *arr1, t_point *arr2, t_fdf *fdf)
{
	int size1;
	int	size2;
	int size;
	int i;
	int j;

	i = 1;
	j = 1;
	size1 = arr1[0].color;
	size2 = arr2[0].color;
	size = size1 > size2 ? size1 : size2;
	while (size > 0 && size1 > 0 && size2 > 0)
	{
		ft_bresenham_line(arr1[i], arr2[j], fdf);
		if (i < size1)
			i++;
		if (j < size2)
			j++;
		size--;
	}
}
