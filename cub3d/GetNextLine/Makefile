# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 16:40:26 by skim              #+#    #+#              #
#    Updated: 2021/01/27 16:48:40 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

HEAHER = get_next_line.HEAHER

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) *.o

fclean : clean
	@$(RM) $(NAME)

re : fclean all

