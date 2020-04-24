/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 00:59:57 by laleta            #+#    #+#             */
/*   Updated: 2019/10/30 21:51:55 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_new_map(void)
{
	t_map		*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->z = 0;
	map->color = 0;
	map->width = 0;
	map->height = 0;
	map->z_min = 0;
	map->z_max = 0;
	map->z_length = 0;
	return (map);
}

t_view	*ft_new_view(t_map *map)
{
	t_view		*view;

	if (!(view = (t_view*)malloc(sizeof(t_view))))
		return (NULL);
	view->zoom = WIDTH / map->width / 2;
	view->angl_x = 0;
	view->angl_y = 0;
	view->angl_z = 0;
	view->angl_step = 0.01;
	view->x_offset = 0;
	view->y_offset = 0;
	view->z_deep = 0;
	view->projection = parallel;
	view->clr_theme = deflt;
	view->clr_nbr = 0;
	return (view);
}

t_fdf	*ft_new_fdf(t_map *map, t_view *view)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))) ||
		!(fdf->mlx = mlx_init()) ||
		!(fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF")) ||
		!(fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)) ||
		!(fdf->z_buf = (int*)malloc(sizeof(int) * WIDTH * HEIGHT)) ||
		!(fdf->x_buf = (int*)malloc(sizeof(int) * WIDTH * HEIGHT)))
		return (NULL);
	fdf->data_addr = mlx_get_data_addr(fdf->image, &(fdf->bits_per_pixel),
									&(fdf->size_line), &(fdf->endian));
	fdf->backgrnd_clr = BLACK;
	fdf->map = map;
	fdf->view = view;
	fdf->state = 0;
	return (fdf);
}
