/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:00:21 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/24 15:05:13 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Приближение/отдаление фигуры с помощью клавиатуры +(-) или колёсика мыши
*/

void		zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == MOUSE_SCROLL_UP)
		fdf->control->zoom++;
	else if (key == NUM_PAD_MINUS || key == MOUSE_SCROLL_DOWN)
		fdf->control->zoom--;
	if (fdf->control->zoom < 1)
		fdf->control->zoom == 1;
	ft_draw(fdf);
}

/*
** Перемещение по карте с помощью стрелок на клавиатуре. Смена цвета.
*/

void		move_or_color(int key)
{
	if (key == MAIN_PAD_C)
		fdf->control->menu ? (fdf->control->menu = 0)
			: (fdf->control->menu = 1);
	else if (key == NUM_PAD_0)
		fdf->control->colo
}