/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 02:27:45 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/15 21:16:11 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	itoa_len(long long int n)
{
	int	size;

	if (n <= 0)
	{
		size = 1;
		n = -n;
	}
	else
		size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(long long int n)
{
	char					*nb;
	unsigned long long int	nbtmp;
	int						size;
	char					sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	size = itoa_len(n);
	nb = malloc(sizeof(char) * (size + 1));
	if (!nb)
		return (NULL);
	nbtmp = (long long int)n * sign;
	nb[size] = '\0';
	while (--size >= 0)
	{
		nb[size] = nbtmp % 10 + '0';
		nbtmp /= 10;
	}
	if (sign < 0)
		nb[0] = '-';
	return (nb);
}
