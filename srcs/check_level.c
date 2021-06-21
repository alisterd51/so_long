/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 23:25:55 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/21 23:32:51 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_file_ext(const char *filename, const char *ext)
{
	int	i;

	i = 0;
	while (filename[i + 1])
		i++;
	while (i >= 0 && filename[i] != '.')
		i--;
	if (i >= 0 && !ft_strcmp(filename + i + 1, ext))
		return (0);
	return (1);
}
