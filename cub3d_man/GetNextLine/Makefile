# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 16:40:26 by skim              #+#    #+#              #
#    Updated: 2021/01/31 17:15:23 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
HEADER_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, get_next_line.c get_next_line_utils.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $^

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@$(RM) -rd $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

