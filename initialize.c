/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:55:04 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/10 20:55:04 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
	fdf->z_min = FT_INT_MAX;
	fdf->z_max = FT_INT_MAX;
	return (fdf);
}