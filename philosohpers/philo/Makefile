NAME = philo

SRCS_DIR = ./srcs
INC_DIR = ./includes
OBJS_DIR = ./objs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix $(SRCS_DIR)/, \
	main.c utils.c routine.c philo.c philo_utils.c exit.c)

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRCS) -lpthread

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf $(OBJS_DIR)

re : fclean all
