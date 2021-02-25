# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 23:46:12 by skim              #+#    #+#              #
#    Updated: 2021/02/25 22:17:41 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
GNL = libgnl.a
LIBFT = libft.a
MLX = libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC_DIR = includes
MLX_DIR = ./mlx
GNL_DIR = ./GetNextLine
LIB_DIR = ./libft
SRCS_DIR = ./srcs

SRCS_EVENT_DIR = /event
SRCS_INIT_DIR = /init
SRCS_MAIN_DIR = /main_loop
SRCS_MAP_DIR = /map_parsing

SRCS = $(addprefix $(SRCS_DIR)/, \
	$(addprefix $(SRCS_EVENT_DIR)/, key_action.c key_event.c)\
	$(addprefix $(SRCS_INIT_DIR)/, main.c make_texture.c)\
	$(addprefix $(SRCS_MAIN_DIR)/, casting_floor.c casting_sprite.c casting_wall.c draw_map.c save_bmp_img.c)\
	$(addprefix $(SRCS_MAP_DIR)/, map_check.c map_error.c map_get_pos.c map_get_road.c map_get.c map_parsing.c map_road_check.c)\
)

all : $(NAME)

$(NAME) : $(LIBFT) $(GNL) $(MLX)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(GNL_DIR)/$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -I$(MLX_DIR) \
	-L./ -lgnl -lft -lmlx \
	-framework OpenGL -framework AppKit -o cub3d $(SRCS)

$(LIBFT) :
	@make -C $(LIB_DIR)
	@cp $(LIB_DIR)/$(LIBFT) .

$(GNL) :
	@make -C $(GNL_DIR)
	@cp $(GNL_DIR)/$(GNL) .

$(MLX) :
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX) .

clean :
	@rm -rf $(NAME)
	@rm -rf tmp_map
	@make -C $(MLX_DIR) clean
	@make -C $(LIB_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@rm -rf $(MLX)
	@rm -rf $(GNL)
	@rm -rf $(LIBFT)
	@make -C $(MLX_DIR) clean
	@make -C $(LIB_DIR) fclean
	@make -C $(GNL_DIR) fclean

re : fclean all

bonus : all
