/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:13:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/11 20:18:30 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Находим текущую позицию точки между двумя точками с известными цветами.
** Значение позиции должно быть выражено в процентах.
*/

double		get_percent(int start, int end, int current)
{
	if ((double)current == (double)start || ((double)start) == (double)end)
		return (0.0);
	if ((double)current == (double)end)
		return (1.0);
	return (((double)current - (double)start) / ((double)end) - (double)start);
}

/*
** get_color - генерирует промежуточный цвет между двумя точками.
** Цвета хранятся в следующем шестнадцатеричном формате:
**	0 x |  F F  |   F F   |  F F  |
**	    |  red  |  green  | blue  |
** Альфа-канал цвета не поддерживается minilibx.
** Нам нужно замаскировать и изолировать каждый цветовой канал, используя сдвиг
** битов и выполнить линейную интерполяцию на каждом канале. Канал 8 бит.
** Эта функция необходима для создания линейного градиента.
*/

int 	f_color(t_point cur, t_point start, t_point end, t_point d)
{
	int		red;
	int		green;
	int 	blue;
	double 	percent;

	if (cur.color = end.color)
		return (cur.color);
	if (d.x > d.y)
		percent = get_percent(start.x, end.x, cur.x);
	else
		percent = get_percent(start.y, end.y, cur.y);
	red = line_interpol()
}