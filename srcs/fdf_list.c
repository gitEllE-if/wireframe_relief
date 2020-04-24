/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 01:01:04 by laleta            #+#    #+#             */
/*   Updated: 2019/05/03 01:02:19 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_zcolor	*ft_create_elem(int z, int color)
{
	t_zcolor	*elem;

	if (!(elem = malloc(sizeof(t_zcolor))))
		return (NULL);
	elem->z = z;
	elem->color = color;
	elem->next = NULL;
	return (elem);
}

void		ft_list_push_front(t_zcolor **begin_list, int z, int color)
{
	t_zcolor	*elem;

	elem = ft_create_elem(z, color);
	elem->next = *begin_list;
	*begin_list = elem;
}

t_zcolor	*ft_list_at(t_zcolor *begin_list, size_t nbr)
{
	t_zcolor	*elem;
	size_t		i;

	i = 0;
	elem = begin_list;
	while (elem)
	{
		if (i == nbr)
			return (elem);
		elem = elem->next;
		i++;
	}
	return (NULL);
}

void		ft_list_clear(t_zcolor **begin_list)
{
	t_zcolor	*elem;
	t_zcolor	*clear;

	elem = *begin_list;
	if (*begin_list)
	{
		while (elem->next)
		{
			clear = elem;
			elem = elem->next;
			free(clear);
		}
		free(elem);
	}
	*begin_list = NULL;
}

int			ft_list_size(t_zcolor *begin_list)
{
	int			elem_cnt;
	t_zcolor	*elem;

	elem_cnt = 0;
	elem = begin_list;
	while (elem)
	{
		elem = elem->next;
		elem_cnt++;
	}
	return (elem_cnt);
}
