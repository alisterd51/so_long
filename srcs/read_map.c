/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:44:30 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/24 21:51:15 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"
#include "so_long.h"

int	read_map(int fd, t_map **map_ptr)
{
	char	*line;
	int		ret_gnl;
	int		ret_add_line;

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
	return (0);
}
