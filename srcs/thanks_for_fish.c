/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thanks_for_fish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:52:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 16:55:54 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "so_long.h"
#include "ft.h"
#include "mlx.h"

#ifdef LINUX

int	byebye(t_mlx *mlx)
{
	char	*count;

	count = ft_itoa(mlx->move_count);
	write(1, count, ft_strlen(count));
	free(count);
	write(1, "\n", 1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit1_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit2_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit3_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit4_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	map_clear(&mlx->map);
	exit(0);
	return (0);
}

#endif

#ifdef MACOS

int	byebye(t_mlx *mlx)
{
	char	*count;

	count = ft_itoa(mlx->move_count);
	write(1, count, ft_strlen(count));
	free(count);
	write(1, "\n", 1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit1_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit2_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit3_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->sprit4_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	map_clear(&mlx->map);
	exit(0);
	return (0);
}

#endif
