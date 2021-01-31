# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 00:33:36 by skim              #+#    #+#              #
#    Updated: 2021/01/31 17:11:43 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
GNL = gnl.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

MMS = libmlx.dylib

OPENGNL = libmlx.a

LMLX = libmlx.dylib libmlx.a

INC_DIR = includes
MLX_DIR = ./mlx
GNL_DIR = ./GetNextLine
LIB_DIR = ./libft
SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS = start.c

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) -I $(MMS_DIR) -I $(OPENGNL_DIR) $(LMLX) $(SRCS) -o $(NAME)

clean :
	rm -rf $(NAME)
	rm -rf $(LMLX)

fclean : clean
	make -C $(MMS_DIR) clean
	make -C $(OPENGNL_DIR) clean

re : fclean all

bonus : all

00 :
	$(CC) -I$(INC_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 00.start.c
	./a.out
	rm -rf ./a.out

01-2 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01-2.2d_map.c
	./a.out
	rm -rf ./a.out

01 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 01.untextured.c
	./a.out
	rm -rf ./a.out

02 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 02.textured.c
	./a.out
	rm -rf ./a.out

03 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 03.img_textured.c
	./a.out
	rm -rf ./a.out

04 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 04.img_floor.c
	./a.out
	rm -rf ./a.out

05 :
	$(CC) -I$(INC_DIR) -L./mlx -lmlx -framework OpenGL -framework AppKit 05.sprite.c
	./a.out
	rm -rf ./a.out


06 :
	$(CC) -I$(GNL_DIR) -I$(INC_DIR) -I$(LIB_DIR)/ -L./lib -lmlx -L$(GNL_DIR) -lgnl -framework OpenGL -framework AppKit 06.map_par.c
	@ ./a.out
	@ rm -rf ./a.out
