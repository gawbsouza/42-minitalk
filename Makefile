# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 10:59:30 by gasouza           #+#    #+#              #
#    Updated: 2022/07/24 07:06:10 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= server client
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
RM			= rm -rf
SRCS_D		= src
INCS		= minitalk.h
INCS_D		= include

LIBS_D		= lib
LIBFT_D 	= $(LIBS_D)/libft
LIBFT_L		= -L$(LIBFT_D) -lft
LIBFT_A 	= $(LIBFT_D)/libft.a
FTPRINTF_D	= $(LIBS_D)/ft_printf
FTPRINTF_L	= -L$(FTPRINTF_D) -lftprintf
FTPRINTF_A 	= $(FTPRINTF_D)/libftprintf.a
LIBS_L		= $(LIBFT_L) $(FTPRINTF_L)
LIBS_I		= -I$(LIBFT_D) -I$(FTPRINTF_D)
LIBS_A		= $(LIBFT_A) $(FTPRINTF_A)

all: $(NAME)

$(NAME): 

server: $(SRCS_D)/server.o $(LIBS_A)
	$(CC) $(CFLAGS) $(LIBS_L) $(LIBS_I) $^ -o server

client: $(SRCS_D)/client.o $(LIBS_A)
	$(CC) $(CFLAGS) $(LIBS_L) $(LIBS_I) $^ -o client

$(LIBFT_A): 
	make -C $(LIBFT_D) 
	
$(FTPRINTF_A): 
	make -C $(FTPRINTF_D) 

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCS_D)  $(LIBS_I) -c $< -o $@

clean:
	$(RM) $(SRCS_D)/server.o $(SRCS_D)/client.o
	make clean -C $(LIBFT_D)
	make clean -C $(FTPRINTF_D)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_D)
	make fclean -C $(FTPRINTF_D)

re: fclean all

.PHONY: all clean fclean re 
