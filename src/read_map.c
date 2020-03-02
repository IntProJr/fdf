/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:32:07 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 11:32:11 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

void			new_coordination_to_stack(t_coord **coords_stack, t_coord *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

t_coord			*last_coord_getting(t_coord **coords_stack)
{
	t_coord *high_coord;

	high_coord = NULL;
	if (coords_stack && *coords_stack)
	{
		high_coord = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (high_coord);
}

void			coords_color_to_arrays(t_coord **coords_stack, t_fdf *fdf)
{
	t_coord		*coordinate;

	fdf->size = fdf->width * fdf->height - 1;
	if ((!(fdf->coords = (int *)ft_memalloc(sizeof(int) * fdf->size + 1)))
		|| (!(fdf->colors = (int *)ft_memalloc(sizeof(int) * fdf->size + 1))))
		for_exit(ERR_MEMORY_ALLOCATION);
	while ((coordinate = last_coord_getting(coords_stack)))
	{
		fdf->coords[fdf->size] = coordinate->z;
		fdf->colors[fdf->size] = coordinate->color;
		if (coordinate->z > fdf->z_max)
			fdf->z_max = coordinate->z;
		if (coordinate->z < fdf->z_min)
			fdf->z_min = coordinate->z;
		fdf->size--;
		free(coordinate);
	}
}

t_coord			*new_coords_init_stack(char *s)
{
	t_coord		*coord;
	int			ptr;

	ptr = 0;
	if (!(coord = (t_coord *)ft_memalloc(sizeof(t_coord))))
		for_exit(ERR_MEMORY_ALLOCATION);
	if ((ptr = check_color_ident(s, ptr, 0)) == -1)
		for_exit(ERR_MAP);
	coord->z = ft_atoi(s);
	coord->color = ptr ? ft_atoi_base(s + ptr, 16) : -1;
	coord->next = NULL;
	return (coord);
}

int				reading_maps(const int fd, t_coord **c_stack, t_fdf *fdf)
{
	char		*line;
	int			result;
	char		**coords;
	int			i;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords = ft_strsplit(line, ' ')))
			for_exit(ERR_MAP_READING);
		i = -1;
		while (coords[++i])
			new_coordination_to_stack(c_stack,
					new_coords_init_stack((coords[i])));
		if (fdf->height == 0)
			fdf->width = i;
		if (fdf->width != ft_wordcount(line, ' '))
			for_exit(ERR_MAP);
		ft_clear_mass(&coords);
		ft_strdel(&line);
		fdf->height++;
	}
	if (!(*c_stack))
		for_exit(ERR_MAP);
	coords_color_to_arrays(c_stack, fdf);
	return (result);
}
