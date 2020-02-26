/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:01:54 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/24 15:39:14 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "for_utilits.h"
#include <math.h>
#include "../minilibx_macos/mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

# define WIDTH				1920
# define HEIGHT				1080
# define RADIAN				0.523599

# define ERR_USAGE					"Usage: ./fdf source_file"
# define ERR_MAP					"Incorrect MAP_FILE"
# define ERR_MAP_READING			"Reading error"
# define ERR_MEMORY_ALLOCATION		"FdF: failed to allocate memory"
# define ERROR_OF_FDF_INITIALIZING		"FdF initialization error"
# define ERR_CONTROL		"Error of control initialization"
# define ERR_FDF_INIT		"FdF error of initializing"

# define FT_INT_MAX			((int)2147483647)
# define FT_INT_MIN			((int)-2147483648)
# define BACKGROUND			0xFFFFFF
# define TEXT_COLOR			0x0078C2
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

# define COLOR_WATER		0x00F7FF
# define COLOR_GREEN		0x00FF00
# define COLOR_SUN			0xF3FF00
# define COLOR_SKY			0x14FCF2
# define COLOR_BLOOD		0xFF0000
# define COLOR_PINK			0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_ORANGE		0xF3AF3D
# define COLOR_ACID_GR		0x80FF00
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
	int 					color;
	struct	s_coord			*next;
}							t_coord;

typedef struct				s_control
{
	int 					projection;
	int						zoom;
	double 					alf;
	double 					bet;
	double					gam;
	float 					z_altitude;
	int 					x_move;
	int 					y_move;
	int						color;
	int 					menu;
}							t_control;

typedef struct				s_mouse
{
	char 					is_pressed;
	int 					x;
	int 					y;
	int						previous_x;
	int 					previous_y;
}							t_mouse;

typedef struct				s_fdf
{
	void					*mlx;
	void					*win;
	void					*img;
	char 					*data_addr;
	int 					bits_per_pixel;
	int 					size_line;
	int 					endian;
	int						width;
	int						height;
	int						*coords;
	int						*colors;
	int						z_min;
	int 					z_max;
	size_t 					size;
	t_control				*control;
	t_mouse					*mouse;
}							t_fdf;



void						fdf_exit(char *s);
t_fdf						*fdf_init(void);
int							read_map(const int fd, t_coord **c_stack, t_fdf *fdf);
void						put_new_coords(t_coord **coords_stack, t_coord *new);
int							ft_check_color(const char *str, int ptr, int i);
t_fdf						*ft_mlx_init(t_fdf *fdf);
void						ft_draw(t_fdf *fdf);
int 						f_color(t_point cur, t_point start, t_point end, t_point d);
int 						ft_get_default_color(int z, t_fdf *fdf);
t_point						project(int x, int y, t_fdf *fdf);
t_control					*control_init(t_fdf *fdf);
t_control					*control_init(t_fdf *fdf);
int							key_press(int key, void *param);
void						zoom(int key, t_fdf *fdf);
int							ft_mouse_press(int button, int x, int y, void *param);

#endif
