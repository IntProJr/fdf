/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:06:34 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:41:25 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include "../includes/for_utilits.h"

void		for_exit(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int			check_color_ident(const char *str, int ptr, int i)
{
	int		counting;

	counting = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (str[i] == ',')
	{
		ptr = i + 1;
		while (str[++i])
		{
			if ((str[i] > 102 && str[i] != 'x') || (str[i] < 48 && str[i] != 44)
				|| (str[i] < 65 && str[i] > 57) || (str[i] > 70 && str[i] < 97))
				return (-1);
			counting++;
		}
	}
	if (counting >= 9)
		return (-1);
	return (ptr);
}

void		menu_printing(t_fdf *fdf, int y)
{
	void	*mlx;
	void	*win;

	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 800, y += 33, FOREST, "Lrosalee");
	mlx_string_put(mlx, win, 1500, y += 33, FOREST, "My Friend menu for You");
	mlx_string_put(mlx, win, 1500, y += 33, TEAL, "exit press ESC");
	mlx_string_put(mlx, win, 1500, y += 33, NAVY, "Zomming + or - ");
	mlx_string_put(mlx, win, 1500, y += 33, CORAL, "Use Arrows for moving");
	mlx_string_put(mlx, win, 1500, y += 33, PURPLE, "* or / for z_altitude");
	mlx_string_put(mlx, win, 1500, y += 33, GOLDEN, "Change color 5 or 0");
	mlx_string_put(mlx, win, 1500, y += 33, TEXT, "Rotation use mousee");
	mlx_string_put(mlx, win, 1500, y += 33, PURPLE, "Rotation x 2 or 8");
	mlx_string_put(mlx, win, 1500, y += 33, FOREST, "Rotation y 4 or 6");
	mlx_string_put(mlx, win, 1500, y += 33, NAVY, "Rotation z < or >");
	mlx_string_put(mlx, win, 1500, y += 33, PURPLE, "I for ISO");
	mlx_string_put(mlx, win, 1500, y += 33, FOREST, "P for parallel");
}

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ESC)
		exit(0);
	if (key == PLUS || key == MINUS)
		zooming(key, fdf);
	else if (key == LEFT || key == RIGHT
		|| key == UP || key == DOWN
		|| key == PAD_0 || key == PAD_5
		|| key == PAD_C)
		moving_and_change_color(key, fdf);
	else if (key == PAD_LESS || key == MORE
		|| key == PAD_4 || key == PAD_6
		|| key == PAD_2 || key == PAD_8)
		rotation_changing(key, fdf);
	else if (key == PAD_STAR || key == PAD_SLASH)
		z_altitude_changing(key, fdf);
	else if (key == PAD_P || key == PAD_I)
		projection_changing(key, fdf);
	return (0);
}
