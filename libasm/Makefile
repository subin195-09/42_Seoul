# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 11:57:59 by skim              #+#    #+#              #
#    Updated: 2021/03/21 12:40:32 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

ASMC = nasm
ASMCFLAGS = -f macho64

AR = ar rc
RM = rm -f

OBJS_DIR = ./objs
OBJS_BONUS_DIR = ./objs_bonus
SRCS_DIR = ./srcs

SRCS = $(addprefix $(SRCS_DIR)/,\
	ft_strlen.s ft_strcpy.s ft_strcmp.s \
	ft_write.s ft_read.s ft_strdup.s)

SRCS_BONUS = $(addprefix $(SRCS_DIR)/, \
	ft_atoi_base.s \
	ft_list_push_front.s \
	ft_list_size.s \
	ft_list_sort.s \
	ft_list_remove_if)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
	@$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	@$(ASMC) $(ASMCFLAGS) $(SRCS)

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_BONUS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_BONUS_DIR)
	@$(ASMC) $(ASMCFLAGS) $(SRCS_BONUS)

$(OBJS_BONUS) :
	@mkdir -p $(OBJS_BONUS)

clean :
	@$(RM) -rd $(OBJS_DIR)
	@$(RM) -rd $(OBJS_BONUS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

test :
	$(ASMC) $(ASMCFLAGS) asm.s
	gcc test.c asm.o
	./a.out
