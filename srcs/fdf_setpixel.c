/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_setpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:48:45 by laleta            #+#    #+#             */
/*   Updated: 2019/10/30 23:38:06 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	x_buf(t_point p, t_fdf *fdf, int j)
{
	if (p.y < fdf->x_buf[j] || fdf->view->angl_x < 0.7854 ||
			fdf->view->angl_x > 3.9270 ||
			(p.z > fdf->z_buf[j] && fdf->view->angl_x > 0.7854 &&
			fdf->view->angl_x < 2.3562) ||
			(p.z < fdf->z_buf[j] && fdf->view->angl_x < 3.927 &&
			fdf->view->angl_x >= 2.3562))
	{
		if (p.y < fdf->x_buf[j])
			fdf->x_buf[j] = p.y;
		if (p.z > fdf->z_buf[j] && fdf->view->angl_x > 0.7854 &&
													fdf->view->angl_x < 2.3562)
			fdf->z_buf[j] = p.z;
		if (p.z < fdf->z_buf[j] && fdf->view->angl_x < 3.927 &&
													fdf->view->angl_x >= 2.3562)
			fdf->z_buf[j] = p.z;
		return (0);
	}
	else
		return (1);
}

static int	z_buf(t_point p, t_fdf *fdf, int j)
{
	if (p.x < fdf->x_buf[j] || fdf->view->angl_z < 0.7854 ||
			fdf->view->angl_z > 3.9270 ||
			(p.z > fdf->z_buf[j] && fdf->view->angl_z > 0.7854 &&
			fdf->view->angl_z < 3.927))
	{
		if (p.x < fdf->x_buf[j])
			fdf->x_buf[j] = p.x;
		if (p.z > fdf->z_buf[j] && fdf->view->angl_z > 0.7854 &&
													fdf->view->angl_z < 3.927)
			fdf->z_buf[j] = p.z;
		return (0);
	}
	else
		return (1);
}

void		ft_set_pixel(t_point p, t_fdf *fdf)
{
	int		i;
	int		hidn;
	int		j;

	hidn = 0;
	if (p.x > 0 && p.x < WIDTH && p.y > 0 && p.y < HEIGHT)
	{
		j = p.x + p.y * WIDTH;
		if (fdf->state & FDF_XBUF)
			hidn = x_buf(p, fdf, j);
		if (fdf->state & FDF_ZBUF)
			hidn = z_buf(p, fdf, j);
		if (!hidn)
		{
			i = p.x * fdf->bits_per_pixel / 8 + p.y * fdf->size_line;
			fdf->data_addr[i] = p.color;
			fdf->data_addr[++i] = p.color >> 8;
			fdf->data_addr[++i] = p.color >> 16;
		}
	}
}
