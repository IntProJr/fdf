/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:06:34 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/24 16:04:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *fdf, int y)
{
	void 	*mlx;
	void 	*win;

	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Guide for menu, my friend");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "ESC for exit");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "+ or -  on numpad for zooming");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Arrows for moving");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "* or / for change z_altitude");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Change color 5 / 0 on numpad");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Rotation : press on mouse & move");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Rotation on x : 2 or 8 on numpad");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Rotation on y : 4 or 6 on numpad");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Rotation on z : < or >");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "ISO projection : I");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT_COLOR, "Parallel projection : P");
}

/*
** Управление вводом ключей с клавиатуры
*/

int 	key_press(int key, void *param)
{
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit (0);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
			|| key == ARROW_UP || key == ARROW_DOWN
			|| key == NUM_PAD_0 || key == NUM_PAD_5
			|| key == MAIN_PAD_C)
		move_or_color(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE
			|| key == NUM_PAD_4 || key == NUM_PAD_6
			|| key == NUM_PAD_2 || key == NUM_PAD_8)
		change_rotation(key, fdf);
	else if (key == NUM_PAD_STAR || key == NUM_PAD_SLASH)
		change_pike(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}