/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:16:21 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 16:27:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "so_long.h"

static void	move(t_mlx *mlx, char *from, char *to)
{
	*from = '0';
	*to = 'P';
	mlx->move_count++;
}

void	left(t_mlx *mlx)
{
	t_map	*map;
	int		i;

	map = mlx->map;
	while (map)
	{
		i = -1;
		while ((map->line)[++i])
		{
			if ((map->line)[i] == 'P' && i > 0 && (map->line)[i - 1] == 'E')
			{
				if (!some_fish_left(mlx->map))
					byebye(mlx);
			}
			else if ((map->line)[i] == 'P' && i > 0
				&& (map->line)[i - 1] != '1')
			{
				return (move(mlx, &((map->line)[i]), &((map->line)[i - 1])));
			}
		}
		map = map->next;
	}
}

void	right(t_mlx *mlx)
{
	t_map	*map;
	int		i;

	map = mlx->map;
	while (map)
	{
		i = -1;
		while ((map->line)[++i])
		{
			if ((map->line)[i] == 'P' && (map->line)[i + 1]
				&& (map->line)[i + 1] == 'E')
			{
				if (!some_fish_left(mlx->map))
					byebye(mlx);
			}
			else if ((map->line)[i] == 'P' && (map->line)[i + 1]
				&& (map->line)[i + 1] != '1')
			{
				return (move(mlx, &((map->line)[i]), &((map->line)[i + 1])));
			}
		}
		map = map->next;
	}
}

void	up(t_mlx *mlx)
{
	t_map	*map;
	int		i;

	map = mlx->map;
	while (map && map->next)
	{
		i = -1;
		while ((map->next->line)[++i])
		{
			if ((map->next->line)[i] == 'P' && (map->line)[i] == 'E')
			{
				if (!some_fish_left(mlx->map))
					byebye(mlx);
			}
			else if ((map->next->line)[i] == 'P' && (map->line)[i] != '1')
			{
				return (move(mlx, &((map->next->line)[i]), &((map->line)[i])));
			}
		}
		map = map->next;
	}
}

void	down(t_mlx *mlx)
{
	t_map	*map;
	int		i;

	map = mlx->map;
	while (map && map->next)
	{
		i = -1;
		while ((map->line)[++i])
		{
			if ((map->line)[i] == 'P' && (map->next->line)[i] == 'E')
			{
				if (!some_fish_left(mlx->map))
					byebye(mlx);
			}
			else if ((map->line)[i] == 'P' && (map->next->line)[i] != '1')
			{
				return (move(mlx, &((map->line)[i]), &((map->next->line)[i])));
			}
		}
		map = map->next;
	}
}
