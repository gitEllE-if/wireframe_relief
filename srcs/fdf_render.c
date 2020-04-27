#include "fdf.h"

t_point	ft_get_point(int x, int y, t_fdf *fdf)
{
	t_point		p;
	size_t		indx;

	p.x = x;
	p.y = y;
	indx = y * fdf->map->width + x;
	p.z = fdf->map->z[indx];
	p.color = (fdf->map->color[indx] == -1 ? ft_set_color(fdf, p.z) :
				fdf->map->color[indx]);
	return (p);
}

void	ft_clear(t_fdf *fdf)
{
	int	*img;
	int	i;

	i = 0;
	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	img = (int *)(fdf->data_addr);
	while (i < HEIGHT * WIDTH)
	{
		img[i] = fdf->backgrnd_clr;
		i++;
	}
	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (fdf->state & FDF_XBUF)
			fdf->x_buf[i] = 2147483647;
		else
			fdf->x_buf[i] = -2147483647;
		fdf->z_buf[i] = -2147483647;
		i++;
	}
}

void	ft_render_frame(t_fdf *fdf, int32_t x, int32_t y)
{
	if (x != fdf->map->width - 1)
		ft_bresenham_line(ft_projection(ft_get_point(x, y, fdf), fdf),
					ft_projection(ft_get_point(x + 1, y, fdf), fdf), fdf);
	if (y != fdf->map->height - 1)
		ft_bresenham_line(ft_projection(ft_get_point(x, y, fdf), fdf),
					ft_projection(ft_get_point(x, y + 1, fdf), fdf), fdf);
	if (x != fdf->map->width - 1 && y != fdf->map->height - 1)
		ft_bresenham_line(ft_projection(ft_get_point(x, y, fdf), fdf),
					ft_projection(ft_get_point(x + 1, y + 1, fdf), fdf), fdf);
}

void	ft_render_solid(t_fdf *fdf, int32_t x, int32_t y)
{
	t_point *arr1;
	t_point *arr2;

	arr1 = NULL;
	arr2 = NULL;
	if (x != fdf->map->width - 1 && y != fdf->map->height - 1)
	{
		arr1 = ft_interpltn(ft_projection(ft_get_point(x, y, fdf), fdf),
					ft_projection(ft_get_point(x + 1, y, fdf), fdf), 1, 0);
		arr2 = ft_interpltn(ft_projection(ft_get_point(x, y + 1, fdf), fdf),
					ft_projection(ft_get_point(x + 1, y + 1, fdf), fdf), 1, 0);
		ft_interp_ar(arr1, arr2, fdf);
	}
	if (arr1)
		free(arr1);
	if (arr2)
		free(arr2);
}

void	ft_fdf_render(t_fdf *fdf, int x, int y)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	ft_clear(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (fdf->state & FDF_SOLID)
				ft_render_solid(fdf, x, y);
			else
				ft_render_frame(fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	ft_put_menu(fdf);
}
