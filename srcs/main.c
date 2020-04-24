/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:00:38 by laleta            #+#    #+#             */
/*   Updated: 2019/05/03 04:06:26 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	write(2, "usage: ./fdf map_file.fdf\n", 26);
	return (0);
}

void	fdf(t_map *map)
{
	t_fdf		*fdf;
	t_view		*view;

	view = ft_new_view(map);
	fdf = ft_new_fdf(map, view);
	ft_fdf_render(fdf, 0, 0);
	ft_control_hook(fdf);
	mlx_loop(fdf->mlx);
}

int		main(int argc, char **argv)
{
	int			file_desc;
	t_zcolor	*zcolor;
	t_map		*map;

	zcolor = NULL;
	if (argc != 2)
		return (ft_usage());
	if ((file_desc = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	if (!(map = ft_new_map()) || !ft_get_hwzcolor(file_desc, map, &zcolor, 0))
	{
		write(2, "error\n", 6);
		return (0);
	}
	ft_list_clear(&zcolor);
	fdf(map);
	return (0);
}
