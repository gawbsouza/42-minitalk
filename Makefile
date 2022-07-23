# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 10:59:30 by gasouza           #+#    #+#              #
#    Updated: 2022/07/23 00:43:08 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
SRCS	= server.c build_str.c build_char.c
OBJS	= $(SRCS:.c=.o)
TSRCS	= build_str.c build_char.c
TOBJS	= $(TSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%_test : $(TOBJS) tests/%_test.o 
	$(CC) $(CFLAGS) $^ -o tests/$@
ifeq (run, $(filter run, $(MAKECMDGOALS)))
	tests/$@
endif

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean

.PHONY: run
