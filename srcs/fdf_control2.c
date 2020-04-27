#include "fdf.h"
#include "fdf_control.h"

void		ft_move(int key, t_fdf *fdf)
{
	if (key == ARR_UP)
		fdf->view->y_offset -= 10;
	if (key == ARR_DOWN)
		fdf->view->y_offset += 10;
	if (key == ARR_LEFT)
		fdf->view->x_offset -= 10;
	if (key == ARR_RIGHT)
		fdf->view->x_offset += 10;
	ft_fdf_render(fdf, 0, 0);
}

static void	angl_norm(t_view *view)
{
	if (view->angl_x > 2 * M_PI)
		view->angl_x = 0.0;
	if (view->angl_y > 2 * M_PI)
		view->angl_y = 0.0;
	if (view->angl_z > 2 * M_PI)
		view->angl_z = 0.0;
	if (view->angl_x < 0)
		view->angl_x += 2 * M_PI;
	if (view->angl_y < 0)
		view->angl_y += 2 * M_PI;
	if (view->angl_z < 0)
		view->angl_z += 2 * M_PI;
}

void		ft_rotate(int key, t_fdf *fdf)
{
	if (key == KEY_3)
		fdf->view->angl_step += 0.01;
	if (key == KEY_4)
		fdf->view->angl_step -= 0.01;
	if (fdf->view->angl_step < 0)
		fdf->view->angl_step = 0.01;
	if (key == KEY_U)
		fdf->view->angl_x -= fdf->view->angl_step;
	if (key == KEY_J)
		fdf->view->angl_x += fdf->view->angl_step;
	if (key == KEY_K)
		fdf->view->angl_y += fdf->view->angl_step;
	if (key == KEY_H)
		fdf->view->angl_y -= fdf->view->angl_step;
	if (key == KEY_M)
		fdf->view->angl_z += fdf->view->angl_step;
	if (key == KEY_N)
		fdf->view->angl_z -= fdf->view->angl_step;
	angl_norm(fdf->view);
	ft_fdf_render(fdf, 0, 0);
}

void		ft_zoom(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
		fdf->view->zoom += 0.2;
	if (key == KEY_MINUS)
		fdf->view->zoom -= 0.2;
	if (fdf->view->zoom < 1.0)
		fdf->view->zoom = 1.0;
	ft_fdf_render(fdf, 0, 0);
}

void		ft_z_deep(int key, t_fdf *fdf)
{
	if (key == KEY_Q)
		fdf->view->z_deep += 0.1;
	if (key == KEY_A)
		fdf->view->z_deep -= 0.1;
	ft_fdf_render(fdf, 0, 0);
}
