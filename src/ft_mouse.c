/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:32:29 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/28 15:54:10 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** mouse_pressed_hook - для события нажатия мыши, которое передается
** mlx_hook(). mlx_hook() передаст "int button, int x, int y", а затем
** любые параметры также передаются в mlx_hook () функции, когда мышь нажата.
*/

int 		ft_mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = 1;
	return (0);
}

/*
** Клавиша мыши не нажата (флаг is_pressed на ноль)
*/

int		ft_mouse_not_press(int button, int x, int y, void *param)
{
	t_fdf		*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = 0;
	return (0);
}

/*
** Двигаем мышью
*/

int 	ft_mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->control->bet += (x - fdf->mouse->previous_x) * 0.002;
		fdf->control->alf += (y - fdf->mouse->previous_y) * 0.002;
		ft_draw(fdf);
	}
	return (0);
}