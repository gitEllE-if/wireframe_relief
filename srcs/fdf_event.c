#include "fdf.h"
#include "fdf_control.h"

void	ft_exit(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->image);
	mlx_destroy_window(fdf->mlx, fdf->window);
	free(fdf->map->z);
	free(fdf->map->color);
	free(fdf->map);
	free(fdf->view);
	free(fdf->z_buf);
	free(fdf->x_buf);
	free(fdf);
	exit(0);
}

int		key_press_hook(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == KEY_ESC)
		ft_exit(fdf);
	if (key == ARR_LEFT || key == ARR_RIGHT || key == ARR_UP || key == ARR_DOWN)
		ft_move(key, fdf);
	if (key == KEY_PLUS || key == KEY_MINUS)
		ft_zoom(key, fdf);
	if (key == KEY_U || key == KEY_H || key == KEY_J || key == KEY_K ||
		key == KEY_N || key == KEY_M || key == KEY_3 || key == KEY_4)
		ft_rotate(key, fdf);
	if (key == KEY_Q || key == KEY_A)
		ft_z_deep(key, fdf);
	if (key == KEY_I || key == KEY_O || key == KEY_P || key == KEY_L)
		ft_proj_type(key, fdf);
	if (key == KEY_D || key == KEY_C || key == KEY_G)
		ft_color_type(key, fdf);
	if (key == KEY_W || key == KEY_S)
		ft_backgrnd_clr(key, fdf);
	if (key == KEY_1 || key == KEY_2 || key == KEY_0 || key == KEY_Z ||
																key == KEY_X)
		ft_draw_style(key, fdf);
	return (0);
}

void	ft_control_hook(t_fdf *fdf)
{
	mlx_hook(fdf->window, 2, 0, key_press_hook, fdf);
}
