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

static void	pre_init_mlx(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->mlx_ptr = NULL;
	mlx->mlx_win = NULL;
	mlx->img = NULL;
}

int	init_mlx(t_mlx *mlx, t_map *map)
{
	pre_init_mlx(mlx);
	mlx->map = map;
	mlx->size_square = 40;
	mlx->width = mlx->size_square * map_width(map);
	mlx->height = mlx->size_square * map_height(map);
	mlx->size_line = mlx->width * 4;
	mlx->bpp = 32;
	mlx->endian = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->move_count = 0;
	if (mlx->mlx_ptr == NULL)
		return (fail_init(mlx, 7));
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"so_long");
	if (!mlx->mlx_win || init_images(mlx))
		return (fail_init(mlx, 8));
	return (0);
}
