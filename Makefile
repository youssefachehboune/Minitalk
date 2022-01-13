# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:01:55 by yachehbo          #+#    #+#              #
#    Updated: 2022/01/11 19:03:49 by yachehbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
CC = cc
CLIENT = client
SERVER = server

PRINTF = ft_printf/libftprintf.a

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c server.c ft_printf/src/*.c
		@cd ft_printf; make;
		$(CC) $(CFLAGS) client.c $(PRINTF) ft_atoi.c -o client
$(SERVER) : client.c server.c
		$(CC) $(CFLAGS) server.c $(PRINTF) -o server

clean:
	rm -rf ft_printf/obj
fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(PRINTF)

re: fclean all
