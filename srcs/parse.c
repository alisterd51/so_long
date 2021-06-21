/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:08:50 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/21 23:36:37 by anclarma         ###   ########.fr       */
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

static int	is_charset(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E');
}

static int	check_line(char *line)
{
	if (*line && *line != '1')
		return (1);
	while (*line && *(line + 1))
	{
		if (!is_charset(*line))
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
		|| !is_in_map('P', *map_ptr))
		return (6);
	if (check_wall(*map_ptr))
		return (6);
	return (0);
}

int	parse(t_map **map_ptr, const char *map_file)
{
	int		fd;
	int		ret_gnl;
	int		ret_add_line;
	char	*line;

	if (check_file_ext(map_file, "ber"))
		return (9);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (2);
	line = NULL;
	ret_gnl = get_next_line(fd, &line);
	ret_add_line = 0;
	while (ret_gnl > 0 && !ret_add_line)
	{
		ret_add_line = add_line_to_map(line, map_ptr);
		line = NULL;
		ret_gnl = get_next_line(fd, &line);
	}
	if (ret_gnl < 0)
		return (3);
	if (ret_add_line)
		return (4);
	if (close(fd))
		return (5);
	return (check_map(map_ptr));
}
