# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/21 16:53:40 by skim              #+#    #+#              #
#    Updated: 2021/05/25 15:19:29 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(CHECKER) $(PUSH_SWAP)

LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
SRCS_DIR = ./srcs
PUSH_DIR = push_swap
CHECKER_DIR = checker
DO_DIR = do
INC_DIR = ./includes

SRCS_COMMON = $(addprefix $(SRCS_DIR)/, \
	stack_check.c stack_check_2.c stack_make.c stack_utils.c stack_utils_2.c)

SRCS_PUSH = $(SRCS_COMMON) \
	$(addprefix $(SRCS_DIR)/$(PUSH_DIR)/, \
	main.c sort_main.c \
	sort_less.c sort_exec.c sort_a_to_b.c sort_b_to_a.c)

SRCS_CHECKER = $(SRCS_COMMON) \
	$(addprefix $(SRCS_DIR)/$(CHECKER_DIR)/, main.c get_instruction.c)

SRCS_DO = $(addprefix $(SRCS_DIR)/$(DO_DIR)/, \
	do_sa.c do_sb.c do_ss.c \
	do_pa.c do_pb.c \
	do_ra.c do_rb.c do_rr.c \
	do_rra.c do_rrb.c do_rrr.c)

all : $(NAME)

$(PUSH_SWAP) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) \
	-I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft \
	$(SRCS_PUSH) $(SRCS_DO) -o push_swap

$(CHECKER) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) \
	-I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft \
	$(SRCS_CHECKER) $(SRCS_DO) -o checker

$(LIB_DIR)/$(LIBFT) :
	@make -C $(LIB_DIR)

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@make -C $(LIB_DIR) fclean

re : fclean all
