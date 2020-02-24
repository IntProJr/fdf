/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:32:29 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/24 15:32:29 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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