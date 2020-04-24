/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:08:01 by laleta            #+#    #+#             */
/*   Updated: 2019/05/03 00:57:46 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_color.h"

float	ft_get_ratio(int min, int max, int crnt)
{
	float	range;
	float	position;

	range = max - min;
	position = crnt - min;
	if (range == 0)
		return (1.0);
	return (position / range);
}

int		ft_set_z(t_point p, t_point p1, t_point p2, int *delta)
{
	float	ratio;
	int		z;

	if (p.z == p2.z)
		return (p.z);
	if (delta[0] > delta[1])
		ratio = ft_get_ratio(p1.x, p2.x, p.x);
	else
		ratio = ft_get_ratio(p2.y, p1.y, p.y);
	z = (1 - ratio) * p1.z + ratio * p2.z;
	return (z);
}

int		ft_set_gradnt(t_point p, t_point p1, t_point p2, int *delta)
{
	float	ratio;
	int		r;
	int		g;
	int		b;

	if (p.color == p2.color)
		return (p.color);
	if (delta[0] > delta[1])
		ratio = ft_get_ratio(p1.x, p2.x, p.x);
	else
		ratio = ft_get_ratio(p1.y, p2.y, p.y);
	r = (1 - ratio) * ((p1.color >> 16) & 255) +
		ratio * ((p2.color >> 16) & 255);
	g = (1 - ratio) * ((p1.color >> 8) & 255) +
		ratio * ((p2.color >> 8) & 255);
	b = (1 - ratio) * (p1.color & 255) +
		ratio * (p2.color & 255);
	return ((r << 16) | (g << 8) | b);
}

int		ft_color_deep(float ratio, t_fdf *fdf)
{
	if (ratio < 0.3)
		return (ft_atoi_base(g_col_tab[fdf->view->clr_nbr],
				"0123456789abcdef"));
	else if (ratio < 0.7)
		return (ft_atoi_base(g_col_tab[fdf->view->clr_nbr + 1],
				"0123456789abcdef"));
	else
		return (ft_atoi_base(g_col_tab[fdf->view->clr_nbr + 2],
				"0123456789abcdef"));
			return (ft_atoi_base(g_col_tab[fdf->view->clr_nbr],
						"0123456789abcdef"));
}

int		ft_set_color(t_fdf *fdf, int z)
{
	float	ratio;

	if (fdf->view->clr_theme == deflt)
		return (DEF_CLR);
	if (fdf->view->clr_nbr > 50)
		fdf->view->clr_nbr = 0;
	if (fdf->view->clr_theme == custom)
		return (ft_atoi_base(g_col_tab[fdf->view->clr_nbr],
				"0123456789abcdef"));
		if (fdf->view->clr_theme == gradient)
	{
		ratio = ft_get_ratio(fdf->map->z_min, fdf->map->z_max, z);
		return (ft_color_deep(ratio, fdf));
	}
	return (DEF_CLR);
}
