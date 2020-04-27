#include "fdf.h"

int	ft_check_z(char *s)
{
	if (*s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	return (*s == '\0');
}

int	ft_check_color(char *s)
{
	if (*s == '0')
		s++;
	else
		return (0);
	if (*s == 'x' || *s == 'X')
		s++;
	else
		return (0);
	while ((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= 'F'))
		s++;
	return (*s == '\0');
}

int	ft_fill_zcolor(char *s, int i, t_zcolor **zcolor, char **tab)
{
	if (!(tab = ft_strsplit(s, ',')))
		return (0);
	if (!ft_check_z(tab[0]))
	{
		ft_free_wordtab(tab);
		return (0);
	}
	if (tab[1])
	{
		while (tab[1][i])
		{
			tab[1][i] = (char)ft_toupper(tab[1][i]);
			i++;
		}
		if (tab[2] != 0 || !ft_check_color(tab[1]))
		{
			ft_free_wordtab(tab);
			return (0);
		}
	}
	ft_list_push_front(zcolor, ft_atoi(tab[0]),
		(tab[1] == 0 ? -1 : ft_atoi_base(tab[1] + 2, "0123456789ABCDEF")));
	ft_free_wordtab(tab);
	return (1);
}

int	ft_parse_line(char *line, t_zcolor **zcolor)
{
	int		i;
	int		crdnt_cnt;
	char	**tab;
	char	**tab1;

	tab1 = NULL;
	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
	i = 0;
	crdnt_cnt = 0;
	while (tab[i])
	{
		if ((!ft_isdigit(tab[0][0]) && tab[0][0] != '-' && tab[0][0] != '+') ||
									!ft_fill_zcolor(tab[i], 2, zcolor, tab1))
		{
			ft_free_wordtab(tab);
			return (0);
		}
		crdnt_cnt++;
		i++;
	}
	ft_free_wordtab(tab);
	return (crdnt_cnt);
}

int	ft_get_hwzcolor(int file_desc, t_map *map, t_zcolor **zcolor, int ret)
{
	char	*line;
	int		width;
	int		width_cur;
	int		height;

	width = 0;
	height = 0;
	while ((ret = get_next_line(file_desc, &line)) > 0)
	{
		if (ret == -1 || !(width_cur = ft_parse_line(line, zcolor))
		|| (height && (width != width_cur)))
		{
			return (0);
			ft_strdel(&line);
		}
		height++;
		width = width_cur;
		ft_strdel(&line);
	}
	if (!ft_list_to_arr(map, *zcolor))
		return (0);
	map->width = width;
	map->height = height;
	return (1);
}
