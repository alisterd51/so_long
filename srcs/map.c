/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:52:35 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/13 19:31:03 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "ft.h"

int	map_width(t_map *map)
{
	return (ft_strlen(map->line));
}

int	map_height(t_map *map)
{
	int	height;

	height = 0;
	while (map)
	{
		height++;
		map = map->next;
	}
	return (height);
}

char	get_case(t_map *map, int width, int height)
{
	while (height-- > 0)
		map = map->next;
	return ((map->line)[width]);
}

void	map_clear(t_map **map_ptr)
{
	t_map	*line;
	t_map	*next;

	line = *map_ptr;
	while (line)
	{
		next = line->next;
		free(line->line);
		free(line);
		line = next;
	}
	*map_ptr = NULL;
}

int	add_line_to_map(char *line, t_map **map_ptr)
{
	t_map	*ptr;

	if (*map_ptr == NULL)
	{
		*map_ptr = (t_map *)malloc(sizeof(t_map));
		if (*map_ptr == NULL)
			return (1);
		(*map_ptr)->line = line;
		(*map_ptr)->next = NULL;
	}
	else
	{
		ptr = *map_ptr;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = (t_map *)malloc(sizeof(t_map));
		if (ptr->next == NULL)
			return (1);
		ptr->next->line = line;
		ptr->next->next = NULL;
	}
	return (0);
}
