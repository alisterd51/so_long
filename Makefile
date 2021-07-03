# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anclarma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 14:10:03 by anclarma          #+#    #+#              #
#    Updated: 2021/07/03 19:00:28 by anclarma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CFILES		= so_long.c			\
			  ft_error.c		\
			  parse.c			\
			  read_map.c		\
			  check_wall.c		\
			  check_level.c		\
			  map.c				\
			  play.c			\
			  get_next_line.c	\
			  ft_atoi.c			\
			  ft_itoa.c			\
			  ft_is.c			\
			  ft_secure_atoi.c	\
			  ft_strcmp.c		\
			  ft_strcpy.c		\
			  ft_strdup.c		\
			  ft_strjoin.c		\
			  ft_strlen.c		\
			  ft_putnbr.c		\
			  move.c			\
			  fish.c			\
			  init_mlx.c		\
			  lst_img.c			\
			  lst_get_img.c		\
			  thanks_for_fish.c
SRCS		= $(addprefix srcs/,$(CFILES))
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)


CC			= cc
UNAME       := $(shell uname)
CFLAGS		= -Wall -Wextra -Werror -MMD
CINCLUDES	= -I includes/
CLIBS		=

ifeq ($(UNAME),Darwin)
    PATH_MLX = minilibx-mac
    CINCLUDES += -I $(PATH_MLX)/
    CLIBS += -L $(PATH_MLX)/ -lmlx -framework OpenGL -framework AppKit
endif
ifeq ($(UNAME),Linux)
    PATH_MLX = minilibx-linux
    CINCLUDES += -I $(PATH_MLX)/
    CLIBS += -L $(PATH_MLX)/ -lmlx -lXext -lX11
endif

all:		$(NAME)

$(NAME):	$(OBJS) $(PATH_MLX)/libmlx.a
			$(CC) $(CFLAGS) $(CINCLUDES) $(OBJS) $(CLIBS) -o $(NAME)

-include $(DEPS)
.c.o:
			$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $(<:.c=.o)

$(PATH_MLX)/libmlx.a:
			make -C $(PATH_MLX) all

bonus:		$(NAME)

clean:
			rm -rf $(OBJS) $(DEPS)
			make -C $(PATH_MLX) clean

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
