#include "fdf.h"
#include "fdf_menu.h"

void	ft_put_circle(t_fdf *fdf, int x_cntr, int y_cntr, int y)
{
	int	x;
	int delta;
	int error;

	x = 0;
	delta = 1 - 2 * y;
	while (y >= 0)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x_cntr + x, y_cntr + y, FRAME_CLR);
		mlx_pixel_put(fdf->mlx, fdf->window, x_cntr + x, y_cntr - y, FRAME_CLR);
		mlx_pixel_put(fdf->mlx, fdf->window, x_cntr - x, y_cntr + y, FRAME_CLR);
		mlx_pixel_put(fdf->mlx, fdf->window, x_cntr - x, y_cntr - y, FRAME_CLR);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
		{
			delta += 2 * ++x + 1;
			continue ;
		}
		if ((delta > 0) && (error > 0))
		{
			delta -= 2 * --y + 1;
			continue ;
		}
		delta += 2 * (++x - y--);
	}
}

void	ft_put_frame(t_fdf *fdf)
{
	int x;
	int y;

	x = FR_X1;
	y = FR_Y1;
	while (x <= FR_X2)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x, FR_Y1, FRAME_CLR);
		mlx_pixel_put(fdf->mlx, fdf->window, x, FR_Y2, FRAME_CLR);
		x++;
	}
	while (y <= FR_Y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, FR_X1, y, FRAME_CLR);
		mlx_pixel_put(fdf->mlx, fdf->window, FR_X2, y, FRAME_CLR);
		y++;
	}
}

void	ft_put_menu2(t_fdf *fdf, int y)
{
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 45, TXT_CLR2, "background");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR2, "W light");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR2, "S dark");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 45, TXT_CLR1, "grid color");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "D default");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "C custom");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "G gradient");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 45, TXT_CLR1, "draw style");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "1 frame");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "2 solid");
	ft_put_circle(fdf, 44, 697, 10);
	ft_put_circle(fdf, 44, 722, 10);
	ft_put_circle(fdf, 44, 747, 10);
	ft_put_circle(fdf, 44, 603, 10);
	ft_put_circle(fdf, 44, 628, 10);
	ft_put_circle(fdf, 44, 490, 10);
	ft_put_circle(fdf, 44, 512, 10);
	ft_put_circle(fdf, 44, 533, 10);
	ft_put_circle(fdf, 84, 421, 10);
	ft_put_circle(fdf, 84, 331, 10);
	ft_put_circle(fdf, 55, 284, 10);
	ft_put_circle(fdf, 125, 284, 10);
	ft_put_circle(fdf, 44, 818, 10);
	ft_put_circle(fdf, 44, 842, 10);
}

void	ft_put_menu(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->window, 82, y += 22, TXT_CLR1, "^");
	mlx_string_put(fdf->mlx, fdf->window, 50, y += 25, TXT_CLR1, "< move >");
	mlx_string_put(fdf->mlx, fdf->window, 82, y += 28, TXT_CLR1, "v");
	mlx_string_put(fdf->mlx, fdf->window, 60, y += 40, TXT_CLR2, "rotate");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 20, TXT_CLR2, "UJ");
	mlx_string_put(fdf->mlx, fdf->window, 85, y += 21, TXT_CLR2, "|");
	mlx_string_put(fdf->mlx, fdf->window, 85, y += 20, TXT_CLR2, "|___HK");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 20, TXT_CLR2, "/");
	mlx_string_put(fdf->mlx, fdf->window, 72, y += 18, TXT_CLR2, "/");
	mlx_string_put(fdf->mlx, fdf->window, 55, y += 20, TXT_CLR2, "NM");
	mlx_string_put(fdf->mlx, fdf->window, 50, y += 40, TXT_CLR1, "- zoom +");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 45, TXT_CLR2, "Q");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 23, TXT_CLR2, "^");
	mlx_string_put(fdf->mlx, fdf->window, 52, y += 22, TXT_CLR2, "relief");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 22, TXT_CLR2, "v");
	mlx_string_put(fdf->mlx, fdf->window, 80, y += 23, TXT_CLR2, "A");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 45, TXT_CLR1, "projection");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 25, TXT_CLR1, "P parallel");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 21, TXT_CLR1, "I iso");
	mlx_string_put(fdf->mlx, fdf->window, 40, y += 21, TXT_CLR1, "O spheric");
	ft_put_menu2(fdf, y);
	ft_put_frame(fdf);
}
