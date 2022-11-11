# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 18:12:12 by dseo              #+#    #+#              #
#    Updated: 2022/01/27 09:45:25 by dseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes/
HEAD = ./includes/ft_func.h ./includes/operator.h
SRCS = ./srcs/ft_func.c ./srcs/operator.c ./srcs/main.c
NAME = do-op
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(HEAD) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
