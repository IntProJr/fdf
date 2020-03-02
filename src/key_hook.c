/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:00:21 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 11:54:58 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

void	zooming(int key, t_fdf *fdf)
{
	if (key == PLUS || key == SCROLL_UP)
		fdf->control->zoom++;
	else if (key == MINUS || key == SCROLL_DOWN)
		fdf->control->zoom--;
	if (fdf->control->zoom < 1)
		fdf->control->zoom = 1;
	drawing(fdf);
}

void	moving_and_change_color(int key, t_fdf *fdf)
{
	if (key == PAD_C)
		fdf->control->menu ? (fdf->control->menu = 0)
		: (fdf->control->menu = 1);
	else if (key == PAD_0)
		fdf->control->color = 1;
	else if (key == PAD_5)
		fdf->control->color = 0;
	else if (key == LEFT)
		fdf->control->x_move -= 10;
	else if (key == RIGHT)
		fdf->control->x_move += 10;
	else if (key == UP)
		fdf->control->y_move -= 10;
	else
		fdf->control->y_move += 10;
	drawing(fdf);
}

void	rotation_changing(int key, t_fdf *fdf)
{
	if (key == PAD_2)
		fdf->control->alf += 0.05;
	else if (key == PAD_8)
		fdf->control->alf -= 0.05;
	else if (key == PAD_4)
		fdf->control->bet -= 0.05;
	else if (key == PAD_6)
		fdf->control->bet += 0.05;
	else if (key == MORE)
		fdf->control->gam += 0.05;
	else if (key == PAD_LESS)
		fdf->control->gam -= 0.05;
	drawing(fdf);
}

void	z_altitude_changing(int key, t_fdf *fdf)
{
	if (key == PAD_STAR)
		fdf->control->z_altitude -= 0.2;
	else if (key == PAD_SLASH)
		fdf->control->z_altitude += 0.2;
	if (fdf->control->z_altitude < 0.2)
		fdf->control->z_altitude = 0.2;
	else if (fdf->control->z_altitude > 10)
		fdf->control->z_altitude = 10;
	drawing(fdf);
}

void	projection_changing(int key, t_fdf *fdf)
{
	fdf->control->alf = 0;
	fdf->control->bet = 0;
	fdf->control->gam = 0;
	if (key == PAD_I)
		fdf->control->projection = 1;
	else if (key == PAD_P)
		fdf->control->projection = 0;
	drawing(fdf);
}
