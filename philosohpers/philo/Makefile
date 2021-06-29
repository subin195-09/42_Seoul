NAME = philo

SRCS_DIR = ./srcs
INC_DIR = ./includes

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

re : fclean all
