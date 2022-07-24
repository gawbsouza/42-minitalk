# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 10:59:30 by gasouza           #+#    #+#              #
#    Updated: 2022/07/23 20:41:11 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= server client
CFLAGS		= -Wall -Wextra -Werror
CC			= cc
RM			= rm -rf
SRCS_D		= src
SRCS		= str_build.c		str_build_new.c		str_build_destroy.c		\
			  char_build.c		char_build_new.c	char_build_destroy.c
OBJS		= $(subst .c,.o,$(addprefix $(SRCS_D)/,$(SRCS)))
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
LIBS_A		= $(LIBFT_A) $(GNL_A) $(FTPRINTF_A)

TSRCS	= build_str.c build_char.c
TOBJS	= $(TSRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBS_A) $(OBJS) $(INCS_D)/$(INCS)

server: $(SRCS_D)/server.o $(OBJS)
	$(CC) $(CFLAGS) $(LIBS_L) $(LIBS_I) $^ -o server

client: $(SRCS_D)/client.o $(OBJS)
	$(CC) $(CFLAGS) $(LIBS_L) $(LIBS_I) $^ -o client

$(LIBFT_A): 
	make -C $(LIBFT_D) 
	
$(FTPRINTF_A): 
	make -C $(FTPRINTF_D) 

%_test : $(TOBJS) tests/%_test.o 
	$(CC) $(CFLAGS) $^ -o tests/$@
ifeq (run, $(filter run, $(MAKECMDGOALS)))
	tests/$@
endif

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCS_D)  $(LIBS_I) -c $< -o $@

clean:
	$(RM) $(SRCS_D)/server.o $(SRCS_D)/client.o $(OBJS)
	make clean -C $(LIBFT_D)
	make clean -C $(FTPRINTF_D)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_D)
	make fclean -C $(FTPRINTF_D)

re: fclean all

.PHONY: all clean fclean re run
