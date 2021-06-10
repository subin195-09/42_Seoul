NAME = philo_bonus

SRCS_DIR = ./srcs
INC_DIR = ./includes
OBJS_DIR = ./objs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(addprefix $(SRCS_DIR)/, \
	main.c utils.c utils_2.c\
	philo_main.c philo_status.c philo_utils.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $(OBJS) -o $(NAME) -lpthread

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

clean :
	@rm -rf $(NAME)

fclean : clean
	@rm -rf $(OBJS_DIR)

re : fclean all
