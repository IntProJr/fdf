/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:13:52 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 11:55:48 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

double		gradient_color(int start, int end, int current)
{
	if (((double)current == (double)start) || ((double)start == (double)end))
		return (0.0);
	if ((double)current == (double)end)
		return (1.0);
	return (((double)current - (double)start) / ((double)end - (double)start));
}

int			color_for_default(int z, t_fdf *fdf)
{
	double	percent;

	percent = gradient_color(fdf->z_min, fdf->z_max, z);
	if (percent < 0.2)
		return ((fdf->control->color) ? TEAL : NAVY);
	else if (percent < 0.4)
		return ((fdf->control->color) ? CORAL : TEAL);
	else if (percent < 0.6)
		return ((fdf->control->color) ? GOLDEN : PURPLE);
	else if (percent < 0.8)
		return ((fdf->control->color) ? NAVY : GOLDEN);
	else
		return ((fdf->control->color) ? SILENA : ORANGE);
}

int			interpolation(int start, int end, double percent)
{
	if (start == end)
		return (start);
	return ((int)((1 - percent) * start + percent * end));
}

int			color_main(t_point cur, t_point start, t_point end, t_point d)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (cur.color == end.color)
		return (cur.color);
	if (d.x > d.y)
		percent = gradient_color(start.x, end.x, cur.x);
	else
		percent = gradient_color(start.y, end.y, cur.y);
	red = interpolation((start.color >> 16) & 0xFF,
						(end.color >> 16) & 0xFF, percent);
	green = interpolation((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percent);
	blue = interpolation(start.color & 0xFF,
			end.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
