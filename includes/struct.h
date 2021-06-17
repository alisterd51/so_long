/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:50:54 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/17 17:33:52 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map	t_map;
struct	s_map
{
	char	*line;
	t_map	*next;
};

typedef struct s_mlx	t_mlx;
struct	s_mlx
{
	t_map	*map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	void	*sprit1_ptr;
	void	*sprit2_ptr;
	void	*sprit3_ptr;
	void	*sprit4_ptr;
	char	*img;
	int		size_square;
	int		width;
	int		height;
	int		size_line;
	int		bpp;
	int		endian;
	int		move_count;
};

#endif
