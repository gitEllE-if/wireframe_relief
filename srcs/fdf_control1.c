#include "fdf.h"
#include "fdf_control.h"

void	ft_proj_type(int key, t_fdf *fdf)
{
	fdf->view->angl_x = 0;
	fdf->view->angl_y = 0;
	fdf->view->angl_z = 0;
	if (key == KEY_I)
		fdf->view->projection = iso;
	if (key == KEY_P)
		fdf->view->projection = parallel;
	if (key == KEY_O)
		fdf->view->projection = spher;
	if (key == KEY_L)
		fdf->view->projection = persp;
	ft_fdf_render(fdf, 0, 0);
}

void	ft_color_type(int key, t_fdf *fdf)
{
	if (key == KEY_D)
		fdf->view->clr_theme = deflt;
	if (key == KEY_C)
	{
		fdf->view->clr_theme = custom;
		fdf->view->clr_nbr++;
	}
	if (key == KEY_G)
	{
		fdf->view->clr_theme = gradient;
		fdf->view->clr_nbr++;
	}
	ft_fdf_render(fdf, 0, 0);
}

void	ft_backgrnd_clr(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->backgrnd_clr = WHITE;
	if (key == KEY_S)
		fdf->backgrnd_clr = BLACK;
	ft_fdf_render(fdf, 0, 0);
}

void	ft_draw_style(int key, t_fdf *fdf)
{
	if (key == KEY_1)
	{
		fdf->state |= FDF_FRAME;
		fdf->state &= ~FDF_SOLID;
	}
	if (key == KEY_2)
	{
		fdf->state |= FDF_SOLID;
		fdf->state &= ~FDF_FRAME;
	}
	if (key == KEY_0)
		fdf->state = (fdf->state & FDF_FAT) ? (fdf->state & ~FDF_FAT) :
														(fdf->state | FDF_FAT);
	if (key == KEY_Z)
		fdf->state = (fdf->state & FDF_ZBUF) ? (fdf->state & ~FDF_ZBUF) :
													(fdf->state | FDF_ZBUF);
	if (key == KEY_X)
		fdf->state = (fdf->state & FDF_XBUF) ? (fdf->state & ~FDF_XBUF) :
													(fdf->state | FDF_XBUF);
	ft_fdf_render(fdf, 0, 0);
}
