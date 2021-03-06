# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 23:46:12 by skim              #+#    #+#              #
#    Updated: 2021/03/05 19:49:00 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
GNL = libgnl.a
LIBFT = libft.a
MLX = libmlx.a
MLX_BETA = libmlxbeta.dylib

CC = gcc -g

CFLAGS = -Wall -Werror -Wextra

INC_DIR = includes
MLX_DIR = ./mlx
MLX_BETA_DIR = ./mlx_beta
GNL_DIR = ./GetNextLine
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS_EVENT_DIR = /event
SRCS_INIT_DIR = /init
SRCS_MAIN_DIR = /main_loop
SRCS_MAP_DIR = /map_parsing
SRCS_BONUS_DIR = /bonus

SRCS = $(addprefix $(SRCS_DIR)/, \
	$(addprefix $(SRCS_EVENT_DIR)/, key_action.c key_event.c key_action_look.c key_exit.c)\
	$(addprefix $(SRCS_INIT_DIR)/, main.c make_texture.c set_init.c)\
	$(addprefix $(SRCS_MAIN_DIR)/, casting_floor.c casting_sprite.c casting_sprite_2.c casting_wall.c casting_wall_2.c draw_map.c save_bmp_img.c resize_y.c)\
	$(addprefix $(SRCS_MAP_DIR)/, map_check.c map_error.c map_max_resolution.c map_get_pos.c map_get_road.c map_get.c map_parsing.c map_road_check.c)\
	$(addprefix $(SRCS_BONUS_DIR)/, sound_bonus.c lifebar_bonus.c animated_bonus.c darker_bonus.c secret_bonus.c))

OPENGL = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MMS = -L$(MLX_BETA_DIR) -lmlxbeta -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL) $(MLX) $(MLX_BETA)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(GNL_DIR)/$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -I$(MLX_DIR) \
	-L./ -lgnl -L./ -lft $(OPENGL) $(MMS) -o $(NAME) $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

$(GNL) :
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) .

$(MLX) :
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) .

$(MLX_BETA) :
	@make -C $(MLX_BETA_DIR)
	@cp $(MLX_BETA_DIR)/$(MLX_BETA) .

clean :
	@rm -rf $(NAME)
	@rm -rf tmp_map
	@make -C $(MLX_DIR) clean
	@make -C $(MLX_BETA_DIR) clean
	@make -C $(LIB_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@rm -rf $(MLX)
	@rm -rf $(MLX_BETA)
	@rm -rf $(GNL)
	@rm -rf $(LIBFT)
	@make -C $(MLX_DIR) clean
	@make -C $(MLX_BETA_DIR) clean
	@make -C $(LIB_DIR) fclean
	@make -C $(GNL_DIR) fclean

re : fclean all

test : clean all
	./cub3D map.cub

bonus : all
