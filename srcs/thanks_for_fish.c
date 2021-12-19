/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thanks_for_fish.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:52:08 by anclarma          #+#    #+#             */
/*   Updated: 2021/12/19 19:17:30 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "so_long.h"
#include "ft.h"
#include "mlx.h"

#ifdef __linux__

int	byebye(t_mlx *mlx)
{
	ft_putnbr(mlx->move_count);
	write(1, "\n", 1);
	clean_img_lst(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	map_clear(&mlx->map);
	exit(0);
	return (0);
}

#endif

#ifdef __MACH__

int	byebye(t_mlx *mlx)
{
	ft_putnbr(mlx->move_count);
	write(1, "\n", 1);
	clean_img_lst(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	map_clear(&mlx->map);
	exit(0);
	return (0);
}

#endif
