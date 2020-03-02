/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:06:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:01:48 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

t_point			point_new(int x, int y, t_fdf *fdf)
{
	t_point		point;
	int			i;

	i = y * fdf->width + x;
	point.x = x;
	point.y = y;
	point.z = fdf->coords[i];
	point.color = (fdf->colors[i] == -1) ?
			color_for_default(point.z, fdf) : fdf->colors[i];
	return (point);
}

void			pixel_puts(t_fdf *fdf, int x, int y, int color)
{
	int			i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = x * 4 + y * fdf->size_line;
		fdf->data_addr[i] = color;
		fdf->data_addr[i + 1] = color >> 8;
		fdf->data_addr[i + 2] = color >> 16;
	}
}

void			line_draw(t_point p1, t_point p2,
		t_fdf *fdf, int tmp)
{
	t_point		delta;
	t_point		sign;
	t_point		cur;
	int			error;

	delta.x = FT_ABS(p2.x - p1.x);
	delta.y = FT_ABS(p2.y - p1.y);
	sign.x = p1.x < p2.x ? 1 : -1;
	sign.y = p1.y < p2.y ? 1 : -1;
	error = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		pixel_puts(fdf, cur.x, cur.y, color_main(cur, p1, p2, delta));
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		tmp = error;
		if (tmp > -delta.x && ((error -= delta.y) || !error))
			cur.x += sign.x;
		if (tmp < delta.y)
		{
			error += delta.x;
			cur.y += sign.y;
		}
	}
}

void			drawing(t_fdf *fdf)
{
	int			x;
	int			y;
	int			*image;
	int			i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bpp / 8));
	image = (int *)(fdf->data_addr);
	i = -1;
	while (++i < HEIGHT * WIDTH)
		image[i] = BACKGROUND;
	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
		{
			if (x != fdf->width - 1)
				line_draw(project(x, y, fdf),
						project(x + 1, y, fdf), fdf, 0);
			if (y != fdf->height - 1)
				line_draw(project(x, y, fdf), project(x, y + 1, fdf), fdf, 0);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	(fdf->control->menu) ? (menu_printing(fdf, 0)) : (fdf->control->menu = 0);
}
