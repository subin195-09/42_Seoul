# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 19:36:22 by skim              #+#    #+#              #
#    Updated: 2021/01/31 17:15:01 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER  = libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

OBJS_DIR = ./objs
SRCS_DIR = ./srcs
HEADER_DIR = ./includes

SRCS = $(addprefix $(SRCS_DIR)/, \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_ltoa.c ft_ultoa.c ft_dtoa.c ft_pow.c ft_frees.c )

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
