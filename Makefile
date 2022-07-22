# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 10:59:30 by gasouza           #+#    #+#              #
#    Updated: 2022/07/22 18:32:37 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
CC		= cc
SRCS	= build_str.c build_char.c
OBJS	= $(SRCS:.c=.o)

%_test : $(OBJS) tests/%_test.o 
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
