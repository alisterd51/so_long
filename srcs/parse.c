/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:08:50 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/24 21:46:34 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "ft.h"
#include "so_long.h"

static int	is_in_map(char c, t_map *map)
{
	char	*line;

	while (map)
	{
		line = map->line;
		while (*line)
		{
			if (line && *line == c)
				return (1);
			line++;
		}
		map = map->next;
	}
	return (0);
}

static int	one_player_in_map(t_map *map)
{
	char	*line;
	int		nb_player;

	nb_player = 0;
	while (map)
	{
		line = map->line;
		while (*line)
		{
			if (line && *line == 'P')
				nb_player++;
			line++;
		}
		map = map->next;
	}
	if (nb_player == 1)
		return (1);
	return (0);
}

static int	check_line(char *line)
{
	if (*line && *line != '1')
		return (1);
	while (*line && *(line + 1))
	{
		if (!ft_ischarset(*line))
			return (1);
		line++;
	}
	if (*line != '1')
		return (1);
	return (0);
}

static int	check_map(t_map **map_ptr)
{
	t_map	*map;
	size_t	len_line;

	if (!*map_ptr)
		return (6);
	map = *map_ptr;
	len_line = ft_strlen(map->line);
	while (map)
	{
		if (ft_strlen(map->line) != len_line || check_line(map->line))
			return (6);
		map = map->next;
	}
	if (!is_in_map('E', *map_ptr) || !is_in_map('C', *map_ptr)
		|| !is_in_map('P', *map_ptr) || !one_player_in_map(*map_ptr))
		return (6);
	if (check_wall(*map_ptr))
		return (6);
	return (0);
}

int	parse(t_map **map_ptr, const char *map_file)
{
	int		fd;
	int		ret_read_map;

	if (check_file_ext(map_file, "ber"))
		return (9);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (2);
	ret_read_map = read_map(fd, map_ptr);
	if (ret_read_map)
		return (ret_read_map);
	if (close(fd))
		return (5);
	return (check_map(map_ptr));
}
