/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:12:16 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/03 12:45:10 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "so_long.h"
#include "mlx.h"

static int	init_images(t_mlx *mlx)
{
	int	err;

	err = add_img(mlx);
	if (!err)
		err = add_xpm(mlx, 'P', "picture/penguin.xpm");
	if (!err)
		err = add_xpm(mlx, 'C', "picture/fish.xpm");
	if (!err)
		err = add_xpm(mlx, 'E', "picture/portal.xpm");
	if (!err)
		err = add_xpm(mlx, '1', "picture/wall.xpm");
	return (err);
}

#ifdef __linux__
static int	fail_init(t_mlx *mlx, int err)
{
	clean_img_lst(mlx);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	return (err);
}
#endif

#ifdef __MACH__
static int	fail_init(t_mlx *mlx, int err)
{
	clean_img_lst(mlx);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
	return (err);
}
#endif

int	init_mlx(t_mlx *mlx, t_map *map)
{
	pre_init_mlx(mlx);
	*mlx = (t_mlx){.map = map,
		.size_square = 40,
		.width = .size_square * map_width(map),
		.height = .size_square * map_height(map),
		.size_line = .width * sizeof(int),
		.bpp = 32,
		.endian = 1,
		.mlx_ptr = mlx_init(),
		.move_count = 0};
	if (mlx->mlx_ptr == NULL)
		return (fail_init(mlx, 7));
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"so_long");
	if (!mlx->mlx_win || init_images(mlx))
		return (fail_init(mlx, 8));
	return (0);
}
