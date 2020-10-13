# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 18:09:00 by skim              #+#    #+#              #
#    Updated: 2020/10/13 18:13:43 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = 

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

SRCS =

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			$(AR) $@ $^

.c.o = $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
