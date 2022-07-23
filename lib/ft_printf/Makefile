# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 20:26:56 by gasouza           #+#    #+#              #
#    Updated: 2022/07/21 19:01:53 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libftprintf.a
SRCS	=	ft_strlen.c			\
			ft_num_base_str.c	\
			ft_print_char.c		\
			ft_print_str.c		\
			ft_print_nbr.c		\
			ft_print_hex.c		\
			ft_print_ptr.c		\
			ft_print_num_base.c	\
			ft_printf.c
INCS	=	ft_printf.h
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf
AR		=	ar -rc

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# === TESTS === #

TEST_DIR	=	tests
TEST_SRCS	=	$(wildcard $(TEST_DIR)/*.c)
TEST_OUTS 	=	$(TEST_SRCS:.c=.out)
TEST_LIB	=	libtest.a
TEST_LIB_DIR= $(TEST_DIR)/libtest

$(TEST_LIB):
	make -C $(TEST_LIB_DIR)

test: $(OBJS) $(TEST_LIB) $(TEST_OUTS)
	@make -C $(TEST_LIB_DIR) fclean
	@make fclean
	clear
	@$(foreach test, $(TEST_OUTS), ./$(test);)
	@$(RM) $(TEST_OUTS)

%_test: $(OBJS) $(TEST_LIB) $(TEST_DIR)/%.out
	@make -C $(TEST_LIB_DIR) fclean
	@make fclean
	clear
	@valgrind --leak-check=full --show-leak-kinds=all $(TEST_DIR)/$(@:_test=.out)
	@$(RM) $(TEST_DIR)/$(@:_test=.out)

%.out: %.c
	$(CC) $(CFLAGS) -g $< -L$(TEST_LIB_DIR) -ltest $(OBJS) -o $@

# ============= #
