/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:06:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/22 15:12:39 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Добавляем новую координату в стэк в начало списка.
*/

void		put_new_coords(t_coord **coords_stack, t_coord *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Выделяем память под список t_coord и записываем туда координату параметра 'z'
** - через atoi и цвет, если он был передан, - с помощью atoi_base.
** Если цвет отсвутствует - значение принимается равным '-1'.
*/

t_coord		*ft_new_coord(char *s)
{
	t_coord	*coord;
	int 	ptr;

	ptr = 0;
	if (!(coord = (t_coord *)ft_memalloc(sizeof(t_coord))))
		fdf_exit(ERR_MEMORY_ALLOCATION);
	if ((ptr = ft_check_color(s, ptr, 0)) == -1)
		fdf_exit(ERR_MAP);
	coord->z = ft_atoi(s);
	coord->color = ptr ? ft_atoi_base(s + ptr, 16) : -1;
	coord->next = NULL;
	return (coord);
}

/*
** Достаём первую (верхнюю) координату стэка.
*/

t_coord		*get_last_coord(t_coord **coords_stack)
{
	t_coord	*top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}

/*
** Перекладываем координаты точек в массив coords, а цвета в массив colors.
** Заносим в структуру данные о самой высокой и самой низкой точке на карте,
** это необходимо для перехода одного цвета в другой.
*/

void		stack_to_arrays(t_coord **coords_stack, t_fdf *fdf)
{
	t_coord 	*coord;

	fdf->size = fdf->width * fdf->height - 1;
	if ((!(fdf->coords = (int *)ft_memalloc(sizeof(int) * fdf->size + 1)))
		|| (!(fdf->colors = (int *)ft_memalloc(sizeof(int) * fdf->size + 1))))
		fdf_exit(ERR_MEMORY_ALLOCATION);
	while ((coord = get_last_coord(coords_stack)))
	{
		fdf->coords[fdf->size] = coord->z;
		fdf->colors[fdf->size] = coord->color;
		if (coord->z > fdf->z_max)
			fdf->z_max = coord->z;
		if (coord->z < fdf->z_min)
			fdf->z_min = coord->z;
		fdf->size--;
		free(coord);
	}
}


/*
** Считываем построчно файл с помощью get_next_line, обрезаем пробельные символы
** через strsplit. Из полученного двумерного массива по одному аргументу
** вынимаем координаты 'z'. Получаем стэк из координат вершин и стэк для цвета.
*/

int			read_map(const int fd, t_coord **c_stack, t_fdf *fdf)
{
	char 	*line;
	int		result;
	char 	**coords;
	int 	i;

	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords = ft_strsplit(line, ' ')))
			fdf_exit(ERR_MAP_READING);
		i = -1;
		while (coords[++i])
			put_new_coords(c_stack, ft_new_coord(coords[i]));
		if (fdf->height == 0)
			fdf->width = i;
		if (fdf->width != ft_wordcount(line, ' '))
			fdf_exit (ERR_MAP);
		ft_clear_mass(&coords);
		ft_strdel(&line);
		fdf->height++;
	}
	if (!(*c_stack))
		fdf_exit(ERR_MAP);
	stack_to_arrays(c_stack, fdf);
	return (result);
}
