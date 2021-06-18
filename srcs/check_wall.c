/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:24:27 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/18 17:56:17 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static int	w_north(t_map *map)
{
	int	i;

	i = 0;
	while (map && (map->line)[i])
	{
		if ((map->line)[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	w_south(t_map *map)
{
	int	i;

	while (map && map->next)
		map = map->next;
	i = 0;
	while (map && (map->line)[i])
	{
		if ((map->line)[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	w_east(t_map *map)
{
	int	i;

	while (map)
	{
		i = 0;
		while ((map->line)[i] && (map->line)[i + 1])
			i++;
		if ((map->line)[i] && (map->line)[i] != '1')
			return (1);
		map = map->next;
	}
	return (0);
}

static int	w_west(t_map *map)
{
	while (map)
	{
		if (*(map->line) && *(map->line) != '1')
			return (1);
		map = map->next;
	}
	return (0);
}

int	check_wall(t_map *map)
{
	return (w_north(map) || w_south(map) || w_east(map) || w_west(map));
}
