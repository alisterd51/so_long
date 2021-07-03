/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:40:15 by anclarma          #+#    #+#             */
/*   Updated: 2021/06/24 21:53:27 by anclarma         ###   ########.fr       */
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
# define ERR8	"error to read xpm file\n"
# define ERR9	"ext file error\n"
# define BACK_COLOR	0x000E3B81
# define TRANSP		-16777216

# ifdef __MACH__
#  define W_KEY			13
#  define A_KEY			0
#  define S_KEY			1
#  define D_KEY			2
#  define ESC_KEY		53
# endif

# ifdef __linux__
#  define W_KEY			119
#  define A_KEY			97
#  define S_KEY			115
#  define D_KEY			100
#  define ESC_KEY		65307
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
** read_map.c
*/
int		read_map(int fd, t_map **map_ptr);

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
void	thanks_for_fish(t_mlx *mlx);

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

/*
** check_level.c
*/
int		check_file_ext(const char *filename, const char *ext);

/*
** lst_img.c
*/
int		add_img(t_mlx *mlx);
int		add_xpm(t_mlx *mlx, char id, char *path);
int		clean_img_lst(t_mlx *mlx);

/*
** lst_get_img.c
*/
int		get_pixel(t_mlx *mlx, char id, int h_img, int w_img);
char	*get_img(t_mlx *mlx, char id);
void	*get_img_ptr(t_mlx *mlx, char id);

#endif
