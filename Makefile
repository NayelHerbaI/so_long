# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Mk                                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naherbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 17:31:50 by naherbal          #+#    #+#              #
#    Updated: 2023/10/13 19:57:00 by naherbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =  src/exit.c					\
		src/ft_split.c				\
		src/main.c					\
		src/map_handling.c			\
		src/print_map.c				\
		src/second_print_map.c		\
		src/third_print_map.c		\
		src/setup.c					\
		src/solve_map.c				\
		src/utils.c					\

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -Imlx

LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

MLX_PATH = ./mlx

MLX = $(MLX_PATH)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	$(MAKE)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
