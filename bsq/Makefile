# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 21:40:46 by ggalon            #+#    #+#              #
#    Updated: 2023/08/30 19:22:23 by ggalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRCS = ft_check_map.c ft_lib.c ft_lib2.c ft_read_map.c ft_read_file.c ft_create_map.c ft_square_map.c ft_stdin.c main.c
OBJS = ${SRCS:.c=.o}
INCL = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCL) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

