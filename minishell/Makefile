# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 21:44:53 by skim              #+#    #+#              #
#    Updated: 2021/04/05 22:28:10 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GNL = libgnl.a
LIBFT = libft.a

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = includes
GNL_DIR = ./GetNextLine
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/,)

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(GNL_DIR)/$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -I$(MLX_DIR) \
	-L./ -lgnl -L./ -lft -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

$(GNL) :
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) .

test : $(LIBFT) $(GNL)
	@$(CC) -I$(INC_DIR) -I$(GNL_DIR)/$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -I$(MLX_DIR) \
	-L./ -lgnl -L./ -lft test.c
	@./a.out
	@rm a.out
