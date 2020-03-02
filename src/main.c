/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:13:54 by lrosalee          #+#    #+#             */
/*   Updated: 2020/03/02 11:29:45 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/for_utilits.h"

t_fdf			*mlx_initialization(t_fdf *fdf)
{
	if (!(fdf->mlx = mlx_init()))
		for_exit(ERROR_OF_FDF_INITIALIZING);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF")))
		for_exit(ERROR_OF_FDF_INITIALIZING);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT)))
		for_exit(ERROR_OF_FDF_INITIALIZING);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
	if (!(fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		for_exit(ERROR_OF_FDF_INITIALIZING);
	fdf->control = initialization_control_screen(fdf);
	return (fdf);
}

void			key_hook_init(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, if_mouse_not_press, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_moving, fdf);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_coord		*c_stack;
	t_fdf		*fdf;

	c_stack = NULL;
	if (argc != 2)
		for_exit(ERR_USAGE);
	if (!((fd = open(argv[1], O_RDONLY)) >= 0))
		for_exit(ERR_MAP);
	if (!(fdf = initialization_fdf()) || reading_maps(fd, &c_stack, fdf) == -1)
		for_exit(ERR_MAP_READING);
	mlx_initialization(fdf);
	drawing(fdf);
	key_hook_init(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
