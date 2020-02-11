/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:06:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/10 21:06:58 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (ptr = ft_check_color(s, ptr, 0) == -1)
		fdf_exit(ERR_MAP);
	coord->z = ft_atoi(s);
	coord->color = ptr ? ft_atoi_base(s + ptr, 16) : -1;
	coord->next = NULL;
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
	}
}
