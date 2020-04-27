#include "fdf.h"

int	ft_z_length(t_map *map, int size)
{
	int	i;

	i = 0;
	map->z_min = map->z[0];
	map->z_max = map->z[0];
	while (i < size)
	{
		if (map->z[i] < map->z_min)
			map->z_min = map->z[i];
		if (map->z[i] > map->z_max)
			map->z_max = map->z[i];
		i++;
	}
	return (map->z_max - map->z_min);
}

int	ft_list_to_arr(t_map *map, t_zcolor *begin_list)
{
	int			size;
	int			i;
	t_zcolor	*elem;

	if ((size = ft_list_size(begin_list)) <= 2)
		return (0);
	if (!(map->z = (int *)malloc(sizeof(int) * size)))
		return (0);
	if (!(map->color = (int *)malloc(sizeof(int) * size)))
	{
		free(&(map->z));
		return (0);
	}
	i = size - 1;
	elem = begin_list;
	while (i >= 0)
	{
		map->z[i] = elem->z;
		map->color[i] = elem->color;
		elem = elem->next;
		i--;
	}
	map->z_length = ft_z_length(map, size);
	return (1);
}
