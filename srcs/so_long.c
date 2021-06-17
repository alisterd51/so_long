/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:26:51 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 15:17:07 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	int		errno;

	map = NULL;
	errno = 0;
	if (ac != 2)
		errno = 1;
	if (!errno)
		errno = parse(&map, av[1]);
	if (!errno)
		errno = play(map);
	map_clear(&map);
	if (errno)
		return (ft_error(errno));
	return (0);
}
