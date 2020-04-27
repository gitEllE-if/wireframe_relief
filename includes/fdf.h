#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include "libft.h"
# include "mlx.h"

# define HEIGHT		1200
# define WIDTH		1800
# define DEF_CLR	6535423
# define BLACK		0
# define WHITE		13882323

# define FDF_SOLID	1
# define FDF_FRAME	2
# define FDF_FAT	4
# define FDF_ZBUF	8
# define FDF_XBUF	16

typedef struct		s_zcolor
{
	int				z;
	int				color;
	struct s_zcolor	*next;
}					t_zcolor;

typedef enum		e_projection
{
	none,
	parallel,
	iso,
	persp,
	spher
}					t_projection;

typedef	enum		e_clr_theme
{
	deflt,
	custom,
	gradient
}					t_clr_theme;

typedef struct		s_map
{
	int				height;
	int				width;
	int				*z;
	int				*color;
	int				z_min;
	int				z_max;
	int				z_length;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_view
{
	int				x_offset;
	int				y_offset;
	float			z_deep;
	float			zoom;
	float			angl_x;
	float			angl_y;
	float			angl_z;
	float			angl_step;
	t_projection	projection;
	t_clr_theme		clr_theme;
	int				clr_nbr;
}					t_view;

typedef struct		s_fdf
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*data_addr;
	uint8_t			state;
	int				*z_buf;
	int				*x_buf;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				backgrnd_clr;
	int				data;
	t_map			*map;
	t_view			*view;
}					t_fdf;

t_map				*ft_new_map(void);
t_view				*ft_new_view(t_map *map);
t_fdf				*ft_new_fdf(t_map *map, t_view *view);
void				ft_fdf_render(t_fdf *fdf, int x, int y);
void				ft_proj_type(int key, t_fdf *fdf);
void				ft_color_type(int key, t_fdf *fdf);
void				ft_draw_style(int key, t_fdf *fdf);
void				ft_backgrnd_clr(int key, t_fdf *fdf);
void				ft_control_hook(t_fdf *fdf);
void				ft_move(int key, t_fdf *fdf);
void				ft_rotate(int key, t_fdf *fdf);
void				ft_zoom(int key, t_fdf *fdf);
void				ft_z_deep(int key, t_fdf *fdf);
void				ft_exit(t_fdf *fdf);
void				ft_x_rotate(int *y, int *x, float angl_x);
void				ft_y_rotate(int *x, int *z, float angl_y);
void				ft_z_rotate(int *x, int *y, float angl_z);
void				ft_put_menu(t_fdf *fdf);
t_point				ft_projection(t_point p, t_fdf *fdf);
int					ft_get_hwzcolor(int fd, t_map *map, t_zcolor **zcol, int r);
int					ft_set_color(t_fdf *fdf, int z);
int					ft_set_gradnt(t_point p, t_point p1, t_point p2, int *delt);
int					ft_set_z(t_point p, t_point p1, t_point p2, int *delt);
void				ft_set_pixel(t_point p, t_fdf *fdf);
int					ft_list_to_arr(t_map *map, t_zcolor *zcolor);
void				ft_list_push_front(t_zcolor **begin_list, int z, int color);
void				ft_list_clear(t_zcolor **begin_list);
int					ft_list_size(t_zcolor *begin_list);
void				ft_bresenham_line(t_point p1, t_point p2, t_fdf *fdf);
t_point				*ft_interpltn(t_point p1, t_point p2, int i, int size);
void				ft_interp_ar(t_point *arr1, t_point *arr2, t_fdf *fdf);

#endif
