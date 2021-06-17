/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:12:16 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 17:39:24 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "so_long.h"
#include "mlx.h"

static void	init_images(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->sprit1_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "picture/penguin.xml",
			&(mlx->size_square), &(mlx->size_square));
	mlx->sprit2_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "picture/fish.xml",
			&(mlx->size_square), &(mlx->size_square));
	mlx->sprit3_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "picture/portal.xml",
			&(mlx->size_square), &(mlx->size_square));
	mlx->sprit4_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "picture/wall.xml",
			&(mlx->size_square), &(mlx->size_square));
}

int	init_mlx(t_mlx *mlx, t_map *map)
{
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
		return (7);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"so_long");
	init_images(mlx);
	if (!mlx->img_ptr || !mlx->sprit1_ptr || !mlx->sprit2_ptr
		|| !mlx->sprit3_ptr || !mlx->sprit4_ptr)
		return (8);
	mlx->img = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), &(mlx->size_line),
			&(mlx->endian));
	return (0);
}
