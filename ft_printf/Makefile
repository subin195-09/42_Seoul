# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 18:09:00 by skim              #+#    #+#              #
#    Updated: 2020/11/03 19:02:20 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

LIB_DIR = ./libft

SRCS = ft_printf.c ft_check_format.c ft_make_result.c \
	ft_make_result_int.c ft_make_result_int_second.c ft_make_result_int_third.c \
	ft_make_result_char.c ft_make_result_char_encoder.c \
	ft_make_result_base.c ft_make_result_base_second.c \
	ft_make_result_ptr.c ft_make_result_per.c \
	ft_make_result_float.c \
	ft_zero_check.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR)
	cp $(LIB_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(OBJS) :
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $(SRCS)

clean :
	make -C $(LIB_DIR) clean
	$(RM) $(OBJS_LIB) $(OBJS)

fclean : clean
	$(RM) $(LIB_DIR)/$(LIBFT)
	$(RM) $(NAME)

re : fclean all

test :
	@($(CC) $(CFLAGS) -I $(LIB_DIR) test.c $(SRCS) $(LIB_DIR)/*.c)
	@echo "\033[38;5;214m"
	@(./a.out)
	@(rm a.out)

.PHONY : all clean fclean re
