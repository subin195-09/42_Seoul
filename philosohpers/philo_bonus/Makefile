NAME = philo_bonus

SRCS_DIR = ./srcs
INC_DIR = ./includes

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix $(SRCS_DIR)/, \
	main_bonus.c utils_bonus.c utils_2_bonus.c exit_bonus.c\
	philo_bonus.c routine_bonus.c philo_utils_bonus.c philo_done_bonus.c)

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRCS) -lpthread

clean :
	@rm -rf $(NAME)

fclean : clean

re : fclean all
