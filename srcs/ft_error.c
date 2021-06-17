/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:01:02 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/16 13:47:10 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "so_long.h"
#include "ft.h"

/*
** pensez a ajouter un msg en fonction d'errno
*/

int	ft_error(int errno)
{
	const char	*err_msg[9] = {ERR0, ERR1, ERR2, ERR3, ERR4, ERR5, ERR6,
								ERR7, ERR8};

	write(2, "Error\n", 6);
	write(2, err_msg[errno], ft_strlen(err_msg[errno]));
	return (errno);
}
