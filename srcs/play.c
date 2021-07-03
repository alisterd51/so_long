/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:27:43 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/18 21:05:12 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "so_long.h"
#include "ft.h"
#include "mlx.h"

static void	print_sprit(t_mlx *mlx, int width, int height)
{
	int		w_img;
	int		h_img;
	int		pixel;
	char	*image;

	image = get_img(mlx, 0);
	w_img = width % 40;
	h_img = height % 40;
	pixel = height * mlx->width + width;
	((int *)(image))[pixel] = get_pixel(mlx,
			get_case(mlx->map, width / 40, height / 40), h_img, w_img);
	if (((int *)(image))[pixel] == TRANSP)
		((int *)(image))[pixel] = BACK_COLOR;
}

static int	display(t_mlx *mlx)
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win,
		get_img_ptr(mlx, 0), 0, 0);
	return (0);
}

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
	else
		return (1);
	display(mlx);
	ft_putnbr(mlx->move_count);
	write(1, "\r", 1);
	return (0);
}

int	play(t_map *map)
{
	t_mlx	mlx;
	int		err;

	err = init_mlx(&mlx, map);
	if (err)
		return (err);
	display(&mlx);
	mlx_hook(mlx.mlx_win, 2, (1L << 0), keypress, (void *)&mlx);
	mlx_hook(mlx.mlx_win, 17, (1L << 17), byebye, (void *)&mlx);
	mlx_expose_hook(mlx.mlx_win, display, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
