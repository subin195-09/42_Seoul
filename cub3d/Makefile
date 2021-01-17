# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 00:33:36 by skim              #+#    #+#              #
#    Updated: 2021/01/17 23:05:38 by skim             ###   ########.fr        #
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

start : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 00.start.c
	./a.out
	rm -rf ./a.out

2d : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01-2.2d_map.c
	./a.out
	rm -rf ./a.out

untex : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01.untextured.c
	./a.out
	rm -rf ./a.out

tex : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 02.textured.c
	./a.out
	rm -rf ./a.out

tex_img : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 03.img_textured.c
	./a.out
	rm -rf ./a.out

floor : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 04.img_floor.c
	./a.out
	rm -rf ./a.out

f : $(LMLX)
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit floor.c
	./a.out
	rm -rf ./a.out
