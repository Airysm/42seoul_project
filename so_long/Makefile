# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 23:25:15 by dseo              #+#    #+#              #
#    Updated: 2022/10/19 02:48:59 by dseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c \
	   so_long_util.c \
	   map.c \
	   image.c \
	   key_press.c \
	   get_next_line.c \
	   get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./ -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I./ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re