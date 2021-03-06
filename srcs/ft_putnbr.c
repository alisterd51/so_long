/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:28:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/03 00:28:21 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	ssize_t	ret;
	char	c;

	if (n == -2147483648)
		ret = write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			ret = write(1, "-", 1);
		}
		if (n > 9)
			ft_putnbr(n / 10);
		c = n % 10 + '0';
		ret = write(1, &c, 1);
	}
	(void)ret;
}
