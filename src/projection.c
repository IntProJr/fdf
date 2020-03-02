/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:02:36 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:40:26 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

void			rotation_on_xyz_coords(int *y, int *z, int *x, t_fdf *fdf)
{
	int			prev_y;
	int			prev_x;

	prev_y = *y;
	prev_x = *x;
	if (fdf->control->alf)
	{
		*y = prev_y * cos(fdf->control->alf) + *z * sin(fdf->control->alf);
		*z = -prev_y * sin(fdf->control->alf) + *z * cos(fdf->control->alf);
	}
	if (fdf->control->bet)
	{
		*x = prev_x * cos(fdf->control->bet) + *z * sin(fdf->control->bet);
		*z = -prev_x * sin(fdf->control->bet) + *z * cos(fdf->control->bet);
	}
	if (fdf->control->gam)
	{
		prev_x = *x;
		prev_y = *y;
		*x = prev_x * cos(fdf->control->gam) - prev_y * sin(fdf->control->gam);
		*y = prev_x * sin(fdf->control->gam) + prev_y * cos(fdf->control->gam);
	}
}

void			iso_projection(int *x, int *y, int z)
{
	int			prev_x;
	int			prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(RADIAN);
	*y = -z + (prev_x + prev_y) * sin(RADIAN);
}

t_point			project(int x, int y, t_fdf *fdf)
{
	t_point		p;

	p = point_new(x, y, fdf);
	p.x *= fdf->control->zoom;
	p.y *= fdf->control->zoom;
	p.z *= fdf->control->zoom / fdf->control->z_altitude;
	p.x -= (fdf->width * fdf->control->zoom) / 2;
	p.y -= (fdf->height * fdf->control->zoom) / 2;
	rotation_on_xyz_coords(&p.x, &p.y, &p.z, fdf);
	if (fdf->control->projection)
		iso_projection(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + fdf->control->x_move;
	p.y += (HEIGHT + fdf->height * fdf->control->zoom) / 2
			+ fdf->control->y_move;
	return (p);
}
