# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 06:20:31 by dseo              #+#    #+#              #
#    Updated: 2022/09/25 09:13:28 by dseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_S = server.c
SRC_C = client.c
OBJ_S = server.o
OBJ_C = client.o

PRINTF = ft_printf/libftprintf.a
PRINTF_DIR = ft_printf

all : $(PRINTF) $(CLIENT) $(SERVER)

$(SERVER) : $(OBJ_S)
	$(CC) $(CFLAGS) $(PRINTF) -o $@ $(OBJ_S)

$(CLIENT) : $(OBJ_C)
	$(CC) $(CFLAGS) $(PRINTF) -o $@ $(OBJ_C)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re