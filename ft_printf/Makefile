# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 18:09:00 by skim              #+#    #+#              #
#    Updated: 2020/10/16 15:21:46 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

HEADER = printf.h
HEADER_LIB =$(LIB_DIR)/libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

LIB_DIR = ./libft

SRCS = ft_check_flag.c ft_printf.c

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
	@(./a.out)
	@(rm a.out)

.PHONY : all clean fclean re
