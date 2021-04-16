# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 21:44:53 by skim              #+#    #+#              #
#    Updated: 2021/04/10 17:24:55 by spark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = includes
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/,)

TEST_SRCS = $(wildcard test*_*.c)


all : $(NAME)

$(NAME) : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./ -lft -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

test : $(LIBFT)
	$(CC) -I$(LIB_DIR)/$(INC_DIR) -L ./ -lft $(TEST_SRCS)
	./a.out
	rm a.out
