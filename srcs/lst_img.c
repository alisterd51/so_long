/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_img.c                                          :+:      :+:    :+:   */
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

static void	add_img_back(t_mlx *mlx, t_img *new_img)
{
	t_img	*ptr;

	if (mlx->img == NULL)
		mlx->img = new_img;
	else
	{
		ptr = mlx->img;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_img;
	}
}

int	add_img(t_mlx *mlx)
{
	t_img	*new_img;

	new_img = (t_img *)malloc(sizeof(t_img));
	if (new_img == NULL)
		return (1);
	new_img->id = '\0';
	new_img->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	if (new_img->img_ptr == NULL)
	{
		free(new_img);
		return (2);
	}
	new_img->img = mlx_get_data_addr(new_img->img_ptr, &(mlx->bpp),
			&(mlx->size_line), &(mlx->endian));
	new_img->next = NULL;
	add_img_back(mlx, new_img);
	return (0);
}

int	add_xpm(t_mlx *mlx, char id, char *path)
{
	t_img	*new_img;

	new_img = (t_img *)malloc(sizeof(t_img));
	if (new_img == NULL)
		return (1);
	new_img->id = id;
	new_img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&(mlx->size_square), &(mlx->size_square));
	if (new_img->img_ptr == NULL)
	{
		free(new_img);
		return (2);
	}
	new_img->img = mlx_get_data_addr(new_img->img_ptr, &(mlx->bpp),
			&(mlx->size_square), &(mlx->endian));
	new_img->next = NULL;
	add_img_back(mlx, new_img);
	return (0);
}

int	clean_img_lst(t_mlx *mlx)
{
	t_img	*ptr1;
	t_img	*ptr2;

	ptr1 = mlx->img;
	while (ptr1)
	{
		ptr2 = ptr1->next;
		if (ptr1->img_ptr)
			mlx_destroy_image(mlx->mlx_ptr, ptr1->img_ptr);
		free(ptr1);
		ptr1 = ptr2;
	}
	return (0);
}
