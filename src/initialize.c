/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:55:04 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/22 16:44:40 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
** width: ширина, height: высота.
** Массивы (int) coord/colors для хранения координат z и цвета точек.
** Максимальный и минимальный размер для высоты/глубины при отрисовке z.
*/

t_fdf		*fdf_init(void)
{
	t_fdf		*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		fdf_exit(ERR_MEMORY_ALLOCATION);
	fdf->width = 0;
	fdf->height = 0;
	fdf->coords = NULL;
	fdf->colors = NULL;
	fdf->z_min = FT_INT_MIN;
	fdf->z_max = FT_INT_MAX;
	return (fdf);
}

/*
** zoom: масштабирование реального размера точек до размера окна при отрисовке.
** z_altitude: изменение реального размера высоты/глубины до заданной.
** projection: флаг на 1, значит проекция будет изометрической
** x_move / y_move: текущее положение цетра карты.
*/

t_control		*control_init(t_fdf *fdf)
{
	t_control	*control;

	if (!(control = (t_control *)ft_memalloc(sizeof(t_control))))
		fdf_exit(ERR_CONTROL);
	control->zoom = FT_MIN(WIDTH / fdf->width / 2, HEIGHT / fdf->height / 2);
	control->alf = 0;
	control->bet = 0;
	control->gam = 0;
	control->projection = 1;
	control->z_altitude = 4;
	control->x_move = 0;
	control->y_move = -150;
	control->color = 0;
	control->menu = 1;
	return (control);
}