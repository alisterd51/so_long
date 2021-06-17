/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:27:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 17:31:47 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "so_long.h"
#include "ft.h"
#include "mlx.h"

static void	set_sea(t_mlx *mlx)
{
	int		width;
	int		height;

	width = -1;
	while (++width < mlx->width)
	{
		height = -1;
		while (++height < mlx->height)
			((int *)(mlx->img))[height * mlx->width + width] = FONT_COLOR;
	}
}

static void	put_sprit(t_mlx *mlx, int width, int height)
{
	if (get_case(mlx->map, width / 40, height / 40) == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->sprit1_ptr, width, height);
	else if (get_case(mlx->map, width / 40, height / 40) == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->sprit2_ptr, width, height);
	else if (get_case(mlx->map, width / 40, height / 40) == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->sprit3_ptr, width, height);
	else if (get_case(mlx->map, width / 40, height / 40) == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
			mlx->sprit4_ptr, width, height);
}

static int	display(t_mlx *mlx)
{
	int		width;
	int		height;
	char	*count;

	count = ft_itoa(mlx->move_count);
	write(1, count, ft_strlen(count));
	free(count);
	write(1, "\r", 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img_ptr, 0, 0);
	width = 0;
	while (width < mlx->width)
	{
		height = 0;
		while (height < mlx->height)
		{
			put_sprit(mlx, width, height);
			height += 40;
		}
		width += 40;
	}
	return (0);
}
/*
static void	print_sprit(t_mlx *mlx, int width, int height)
{
	if (get_case(mlx->map, width / 40, height / 40) == '0')
		((int *)(mlx->img))[height * mlx->width + width] = FONT_COLOR;
	else if (get_case(mlx->map, width / 40, height / 40) == 'P')
		((int *)(mlx->img))[height * mlx->width + width] =
			get_pixel(mlx->sprit1, width % 40, height % 40);
}

static int	display2(t_mlx *mlx)
{
	int		width;
	int		height;

	width = 0;
	while (width < mlx->width)
	{
		height = 0;
		while (height < mlx->height)
		{
			print_sprit(mlx, width, height);
			height++;
		}
		width++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img_ptr, 0, 0);
}
*/
static int	keypress(int key, t_mlx *mlx)
{
	if (key == A_KEY)
		left(mlx);
	else if (key == D_KEY)
		right(mlx);
	else if (key == W_KEY)
		up(mlx);
	else if (key == S_KEY)
		down(mlx);
	else if (key == ESC_KEY)
		byebye(mlx);
	return (0);
}

int	play(t_map *map)
{
	t_mlx	mlx;
	int		err;

	err = init_mlx(&mlx, map);
	if (err)
		return (err);
	set_sea(&mlx);
	mlx_hook(mlx.mlx_win, 2, (1L << 0), keypress, (void *)&mlx);
	mlx_hook(mlx.mlx_win, 17, (1L << 17), byebye, (void *)&mlx);
	mlx_loop_hook (mlx.mlx_ptr, display, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
