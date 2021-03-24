# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 14:55:04 by skim              #+#    #+#              #
#    Updated: 2021/03/24 17:20:15 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

ASMC = nasm
ASMCFLAGS = -f macho64
CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

OBJS_DIR = ./objs
OBJS_BONUS_DIR = ./objs_bonus
SRCS_DIR = ./srcs
SRCS_BONUS_DIR = ./srcs_bonus
TEST_DIR = ./test

SRCS = $(addprefix $(SRCS_DIR)/,\
	ft_strlen.s ft_strcpy.s ft_strcmp.s \
	ft_write.s ft_read.s ft_strdup.s)

SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR)/, \
	ft_list_push_front.s ft_list_size.s)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.s=.o)))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR)/, $(notdir $(SRCS_BONUS:.s=.o)))

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus : $(NAME) $(OBJS_BONUS_DIR) $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS_BONUS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.s
	@$(ASMC) $(ASMCFLAGS) $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR)/%.o : $(SRCS_BONUS_DIR)/%.s
	@$(ASMC) $(ASMCFLAGS) $< -o $@

$(OBJS_BONUS_DIR) :
	@mkdir -p $(OBJS_BONUS_DIR)

clean :
	@$(RM) -rd $(OBJS_DIR)
	@$(RM) -rd $(OBJS_BONUS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

test : $(NAME)
	@$(CC) $(CFLAGS) $(TEST_DIR)/test.c -L./ -lasm
	@./a.out
	@rm a.out

t_bonus : $(NAME)
	@$(CC) $(CFLAGS) $(TEST_DIR)/test_bonus.c -L./ -lasm
	@./a.out
	@rm a.out
