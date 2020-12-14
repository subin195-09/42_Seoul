# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 00:33:36 by skim              #+#    #+#              #
#    Updated: 2020/12/15 00:26:53 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Werror -Wextra

MMS_DIR = ./minilibx_mms_20200219
MMS = libmlx.dylib

OPENGNL_DIR = ./minilibx_opengl_20191021
OPENGNL = libmlx.a

LMLX = libmlx.dylib libmlx.a

INC_DIR = ./include

SRCS = start.c

all : $(NAME)

$(NAME) : $(LMLX)
	$(CC) $(CFLAGS) -I $(MMS_DIR) -I $(OPENGNL_DIR) $(LMLX) $(SRCS) -o $(NAME)

$(LMLX) :
	@(make -C $(MMS_DIR))
	@(make -C $(OPENGNL_DIR))
	@(cp $(MMS_DIR)/libmlx.dylib ./)
	@(cp $(OPENGNL_DIR)/libmlx.a ./)

clean :
	rm -rf $(NAME)
	rm -rf $(LMLX)

fclean : clean
	make -C $(MMS_DIR) clean
	make -C $(OPENGNL_DIR) clean

re : fclean all

bonus : all

test : $(LMLX)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MMS_DIR) -I $(OPENGNL_DIR) $(MMS) $(OPENGNL) $(SRCS)
	./a.out
	rm -rf ./a.out
