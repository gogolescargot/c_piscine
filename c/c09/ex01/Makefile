# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 12:54:33 by ggalon            #+#    #+#              #
#    Updated: 2023/08/28 17:40:29 by ggalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = libft.a
SOURCES = $(addprefix srcs/,ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJECTS := ${SOURCES:.c=.o} 
INCLUDES = includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBRARY)

$(LIBRARY) : $(OBJECTS)
	ar -rcs $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIBRARY)

re: fclean all

.PHONY: all clean fclean re
