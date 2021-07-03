/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:18:25 by anclarma          #+#    #+#             */
/*   Updated: 2021/07/03 14:18:56 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "so_long.h"
#include "mlx.h"

int	get_pixel(t_mlx *mlx, char id, int h_img, int w_img)
{
	t_img	*img;

	img = mlx->img;
	while (img)
	{
		if (img->id == id)
			return (((int *)(img->img))[h_img * 40 + w_img]);
		img = img->next;
	}
	return (BACK_COLOR);
}

char	*get_img(t_mlx *mlx, char id)
{
	t_img	*img;

	img = mlx->img;
	while (img)
	{
		if (img->id == id)
			return (img->img);
		img = img->next;
	}
	return (NULL);
}

void	*get_img_ptr(t_mlx *mlx, char id)
{
	t_img	*img;

	img = mlx->img;
	while (img)
	{
		if (img->id == id)
			return (img->img_ptr);
		img = img->next;
	}
	return (NULL);
}
