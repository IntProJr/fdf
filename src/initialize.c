/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:55:04 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 12:26:32 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

t_fdf			*initialization_fdf(void)
{
	t_fdf		*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		for_exit(ERR_MEMORY_ALLOCATION);
	fdf->width = 0;
	fdf->height = 0;
	fdf->coords = NULL;
	fdf->colors = NULL;
	fdf->z_min = FT_INT_MAX;
	fdf->z_max = FT_INT_MIN;
	return (fdf);
}

t_control		*initialization_control_screen(t_fdf *fdf)
{
	t_control	*control;

	if (!(control = (t_control *)ft_memalloc(sizeof(t_control))))
		for_exit(ERR_CONTROL);
	control->zoom = FT_MIN(WIDTH / fdf->width / 2, HEIGHT / fdf->height / 2);
	control->alf = 0;
	control->bet = 0;
	control->gam = 0;
	control->projection = 1;
	control->z_altitude = 5;
	control->x_move = 0;
	control->y_move = -200;
	control->color = 0;
	control->menu = 1;
	return (control);
}
