CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(CHECKER) $(PUSH_SWAP)

GNL = libgnl.a
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
GNL_DIR = ./GetNextLine
SRCS_DIR = ./srcs
PUSH_DIR = push_swap
CHECKER_DIR = checker
HEADER_DIR = ./includes

SRCS_PUSH = $(addprefix $(SRCS_DIR)/$(PUSH_DIR), )
SRCS_CHECKER = $(addprefix $(SRCS_DIR)/$(CHECKER_DIR), )

all : $(NAME)

$(PUSH_SWAP) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o $(PUSH_SWAP) $(SRCS_PUSH)

$(CHECKER) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) \
	-I$(LIB_DIR)/$(INC_DIR) -L $(LIB_DIR) -lft \
	-I$(GNL_DIR)/$(INC_DIR) -L $(GNL_DIR) -lgnl \
	-o $(CHECKER) $(SRCS_CHECKER)

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean
	@make -C $(GNL_DIR) clean

fclean : clean
	@make -C $(LIB_DIR) fclean
	@make -C $(GNL_DIR) fclean

re : fclean all
