# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/30 19:36:22 by skim              #+#    #+#              #
#    Updated: 2020/09/30 19:38:06 by skim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER  = libft.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar rc
RM = rm -f

BSRCS = $(wildcard *lst*.c)
SRCS = $(filter-out $(BSRCS), $(wildcard *.c))

BOBJS = $(BSRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
			$(AR) $@ $^

bonus : $(BOBJS) $(OBJS)
		$(AR) $(NAME) $^

.c.o : $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
