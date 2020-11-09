# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 18:09:00 by skim              #+#    #+#              #
#    Updated: 2020/11/09 17:52:48 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

LIB_DIR = ./libft
OBJS_DIR = ./objs
SRCS_DIR = ./srcs
HEADER_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, \
	ft_printf.c ft_check_format.c ft_make_result.c \
	ft_make_result_int.c ft_make_result_int_second.c ft_make_result_int_third.c \
	ft_make_result_char.c ft_make_result_char_encoder.c \
	ft_make_result_base.c ft_make_result_base_second.c \
	ft_make_result_ptr.c ft_make_result_per.c \
	ft_make_result_float.c ft_make_result_e.c ft_make_result_e_dtoa.c \
	ft_zero_check.c )

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -I $(LIB_DIR)/$(HEADER_DIR) -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@make -C $(LIB_DIR) clean
	@$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(LIB_DIR)/$(LIBFT)
	@$(RM) $(NAME)

re : fclean all

test :
	@(make)
	@($(CC) $(CFLAGS) -o test.o -c test.c -I $(HEADER_DIR) -I $(LIB_DIR)/$(HEADER_DIR))
	@($(CC) $(CFLAGS) -o a.out test.o -L ./ -l ftprintf)
	@echo "\033[38;5;214m"
	@(./a.out)
	@(make fclean)
	@(rm a.out)
	@(rm test.o)

.PHONY : all clean fclean re
