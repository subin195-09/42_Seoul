# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 18:09:00 by skim              #+#    #+#              #
#    Updated: 2020/10/15 00:08:43 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = printf.h
HEADER_LIB = ./libft/libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

SRCS =

LIB_DIR = ./libft

SRCS_LIB = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c\
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c\
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c\
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c\
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c\
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

OBJS_LIB = $(addprefix $(LIB_DIR)/, $(SRCS_LIB:.c=.o))
OBJS = $(SRCS:.c=.o)
OBJS_DIR = ./objects

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_LIB)
	$(AR) $@ $^

.c.o : $(SRCS_LIB) $(HEADER_LIB) $(SRCS) $(HEADER) $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $^ -o $@
	mv $@ ./objects

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

clean :
	$(RM) -d objects

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
