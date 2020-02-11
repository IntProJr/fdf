/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:13:54 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/11 18:17:18 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** mlx_init: даёт соединение между программным обеспечением и дисплеем
** mlx_new_window: создает новое окно на экране, используя параметры size_x
** и size_y, fdf->mlx - это идентификатор соединения
** mlx_new_image: позволяет манипулировать изображениями
** mlx_get_data_addr: возвращает информацию о созданном изображении.
** bits_per_pixel заполнется количеством битов для представления цвета пикселя
** size_line: кол-во байтов для хранения одной строки изображения в памяти
** endian: нужно сохранять цвет пикселя в изображении с прямым порядком байтов
** (endian == 0) или с прямым порядком байтов (endian == 1).
*/

t_fdf 		*ft_mlx_init(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		fdf_exit(ERROR_OF_FDF_INITIALIZING);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF")))
		fdf_exit(ERROR_OF_FDF_INITIALIZING);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		fdf_exit(ERROR_OF_FDF_INITIALIZING);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	return (fdf);
}


/*
** Инициализация структуры fdf и чтение файла через файловый дескриптор.
** Инициализация функций библиотеки mlx, заполнение окна пикселями.
** Подключение событий клавиатуры/мыши.
*/

int	main(int argc, char *argv[])
{
	int			fd;
	t_coord		*c_stack;
	t_fdf		*fdf;

	c_stack = NULL;
	if (argc != 2)
		fdf_exit(ERR_USAGE);
	if (!((fd = open("42.fdf", O_RDONLY)) >= 0))
		fdf_exit(ERR_MAP);
	if (!(fdf = fdf_init()) || read_map(fd, &c_stack, fdf) == -1)
		fdf_exit(ERR_MAP_READING);
	mlx_init(fdf);





}
