# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 00:33:36 by skim              #+#    #+#              #
#    Updated: 2021/01/27 17:14:21 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
GNL = gnl.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

MMS = libmlx.dylib

OPENGNL = libmlx.a

LMLX = libmlx.dylib libmlx.a

INC_DIR = ./include
MLX_DIR = ./mlx
GNL_DIR = ./GetNextLine

SRCS = start.c

all : $(NAME)

$(NAME) : $(LMLX)
	$(CC) $(CFLAGS) -I $(MMS_DIR) -I $(OPENGNL_DIR) $(LMLX) $(SRCS) -o $(NAME)

$(LMLX) :

clean :
	rm -rf $(NAME)
	rm -rf $(LMLX)

fclean : clean
	make -C $(MMS_DIR) clean
	make -C $(OPENGNL_DIR) clean

re : fclean all

bonus : all

start :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 00.start.c
	./a.out
	rm -rf ./a.out

2d :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01-2.2d_map.c
	./a.out
	rm -rf ./a.out

untex :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01.untextured.c
	./a.out
	rm -rf ./a.out

tex :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 02.textured.c
	./a.out
	rm -rf ./a.out

tex_img :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 03.img_textured.c
	./a.out
	rm -rf ./a.out

floor :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 04.img_floor.c
	./a.out
	rm -rf ./a.out

sprite :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 05.sprite.c
	./a.out
	rm -rf ./a.out

f :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit floor.c
	./a.out
	rm -rf ./a.out

map :
	$(CC) -I$(GNL_DIR) -I$(INC_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 06.map_par.c $(GNL_DIR)/*.c
	@ ./a.out
	@ rm -rf ./a.out
