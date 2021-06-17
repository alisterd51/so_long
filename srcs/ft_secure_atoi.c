/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:32:33 by anclarma          #+#    #+#             */
/*   Updated: 2021/05/13 17:49:57 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define STR_INT_MAX "2147483647"
#define STR_INT_MIN "-2147483648"

/*
** Description:
** 	verifie que la chaine passe a atoi est bien un int compris entre INT_MIN et
** 	INT_MAX.
** Return:
** 	si chaine valide, retourne 1 sinon 0.
*/

static int	check_max(const char *str)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (str[i] < STR_INT_MAX[i])
			return (0);
		else if (str[i] > STR_INT_MAX[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_min(const char *str)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (str[i] < STR_INT_MIN[i + 1])
			return (0);
		else if (str[i] > STR_INT_MIN[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_secure_atoi(const char *str)
{
	int	sign;
	int	size;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	size = 0;
	while (ft_isdigit(*(str + size)))
		size++;
	if (size > 10)
		return (0);
	else if (size == 10 && sign == 1 && check_max(str))
		return (0);
	else if (size == 10 && sign == -1 && check_min(str))
		return (0);
	return (1);
}
