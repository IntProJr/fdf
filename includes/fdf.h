/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:01:54 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:45:41 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

# define WIDTH				1920
# define HEIGHT				1080
# define RADIAN				0.523599

# define FT_INT_MAX			2147483647
# define FT_INT_MIN			-2147483648

# define BACKGROUND			0xFFFFFF
# define TEXT			0x0078C2

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))

# define SILENA				0xA0522D
# define FOREST				0x228B22
# define TEAL				0x008080
# define NAVY				0x000080
# define PURPLE				0x800080
# define GOLDEN				0xDAA520
# define CORAL				0xF08080
# define ORANGE				0xFF4500
# define RADIAN				0.523599

typedef struct				s_point
{
	int						x;
	int						y;
	int						z;
	int						color;
}							t_point;

typedef struct				s_coord
{
	int						z;
	int						color;
	struct s_coord			*next;
}							t_coord;

typedef struct				s_control
{
	int						projection;
	int						zoom;
	double					alf;
	double					bet;
	double					gam;
	float					z_altitude;
	int						x_move;
	int						y_move;
	int						color;
	int						menu;
}							t_control;

typedef struct				s_mouse
{
	char					is_pressed;
	int						x;
	int						y;
	int						previous_x;
	int						previous_y;
}							t_mouse;

typedef struct				s_fdf
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*data_addr;
	int						bpp;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	int						*coords;
	int						*colors;
	int						z_min;
	int						z_max;
	size_t					size;
	t_control				*control;
	t_mouse					*mouse;
}							t_fdf;

t_fdf						*mlx_initialization(t_fdf *fdf);
void						key_hook_init(t_fdf *fdf);
t_fdf						*initialization_fdf(void);
t_control					*initialization_control_screen(t_fdf *fdf);
int							reading_maps(const int fd, t_coord **c_stack,
							t_fdf *fdf);
void						coords_color_to_arrays(t_coord **coords_stack,
							t_fdf *fdf);
void						new_coordination_to_stack(t_coord **coords_stack,
							t_coord *new);
t_coord						*last_coord_getting(t_coord **coords_stack);
t_coord						*new_coords_init_stack(char *s);
void						projection_changing(int key, t_fdf *fdf);
void						z_altitude_changing(int key, t_fdf *fdf);
void						rotation_changing(int key, t_fdf *fdf);
void						moving_and_change_color(int key, t_fdf *fdf);
void						zooming(int key, t_fdf *fdf);
int							mouse_press(int button, int x, int y, void *param);
int							if_mouse_not_press(int button, int x, int y,
							void *param);
int							mouse_moving(int x, int y, void *param);
void						drawing(t_fdf *fdf);
void						line_draw(t_point p1, t_point p2, t_fdf *fdf,
		int tmp);
void						pixel_puts(t_fdf *fdf, int x, int y, int color);
t_point						point_new(int x, int y, t_fdf *fdf);
int							color_main(t_point cur, t_point start, t_point end,
							t_point d);
int							interpolation(int start, int end, double percent);
int							color_for_default(int z, t_fdf *fdf);
double						gradient_color(int start, int end, int current);
t_point						project(int x, int y, t_fdf *fdf);
void						iso_projection(int *x, int *y, int z);
void						rotation_on_xyz_coords(int *y, int *z, int *x,
							t_fdf *fdf);
void						for_exit(char *s);
void						menu_printing(t_fdf *fdf, int y);
int							check_color_ident(const char *str, int ptr, int i);
int							key_press(int key, void *param);

#endif
