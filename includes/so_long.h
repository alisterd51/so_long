/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:40:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/18 17:57:27 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "struct.h"

# define ERR0	"is debug test\n"
# define ERR1	"number of argument error\n"
# define ERR2	"open failure\n"
# define ERR3	"gnl failure\n"
# define ERR4	"malloc failure\n"
# define ERR5	"close failure\n"
# define ERR6	"invalid map\n"
# define ERR7	"mlx error\n"
# define ERR8	"error to read xml file\n"
# define ERR9	"is debug test\n"

# ifdef MACOS
#  define W_KEY			13
#  define A_KEY			0
#  define S_KEY			1
#  define D_KEY			2
#  define ESC_KEY		53
#  define FONT_COLOR	0x000E3B81
# endif

# ifdef LINUX
#  define W_KEY			119
#  define A_KEY			97
#  define S_KEY			115
#  define D_KEY			100
#  define ESC_KEY		65307
#  define FONT_COLOR	0x000E3B81
# endif

/*
** ft_error.c
*/
int		ft_error(int errno);

/*
** parse.c
*/
int		parse(t_map **map_ptr, const char *map_file);

/*
** play.c
*/
int		play(t_map *map);

/*
** init_mlx.c
*/
int		init_mlx(t_mlx *mlx, t_map *map);

/*
** thanks_for_fish.c
*/
int		byebye(t_mlx *mlx);

/*
** move.c
*/
void	left(t_mlx *mlx);
void	right(t_mlx *mlx);
void	up(t_mlx *mlx);
void	down(t_mlx *mlx);

/*
** move.c
*/
int		some_fish_left(t_map *map);

/*
** map.c
*/
int		map_width(t_map *map);
int		map_height(t_map *map);
char	get_case(t_map *map, int width, int height);
void	map_clear(t_map **map_ptr);
int		add_line_to_map(char *line, t_map **map_ptr);

/*
** check_wall.c
*/
int		check_wall(t_map *map);

#endif
