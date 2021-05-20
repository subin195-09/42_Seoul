CHECKER = checker
PUSH_SWAP = push_swap
NAME = $(CHECKER) $(PUSH_SWAP)

LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
SRCS_DIR = ./srcs
PUSH_DIR = push_swap
CHECKER_DIR = checker
DO_DIR = do
INC_DIR = ./includes

SRCS_COMMON = $(addprefix $(SRCS_DIR)/, \
	stack_check.c stack_make.c stack_utils.c)

SRCS_PUSH = $(SRCS_COMMON) \
	$(addprefix $(SRCS_DIR)/$(PUSH_DIR)/, main.c stack_sort.c)
SRCS_CHECKER = $(SRCS_COMMON) \
	$(addprefix $(SRCS_DIR)/$(CHECKER_DIR)/, main.c )
SRCS_DO = $(addprefix $(SRCS_DIR)/$(DO_DIR)/, \
	do_sa.c do_sb.c do_ss.c \
	do_pa.c do_pb.c \
	do_ra.c do_rb.c do_rr.c \
	do_rra.c do_rrb.c do_rrr.c)

all : $(NAME)

$(PUSH_SWAP) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o $(PUSH_SWAP) $(SRCS_PUSH) $(SRCS_DO)

$(CHECKER) : $(LIB_DIR)/$(LIBFT) $(GNL_DIR)/$(GNL)
	@$(CC) $(CFLAGS) -I$(INC_DIR) \
	-I$(LIB_DIR)/$(INC_DIR) -L $(LIB_DIR) -lft \
	-o $(CHECKER) $(SRCS_CHECKER) $(SRCS_DO)

$(LIB_DIR)/$(LIBFT) :
	@make -C $(LIB_DIR)

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@make -C $(LIB_DIR) fclean

re : fclean all

push : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft $(SRCS_PUSH) $(SRCS_DO) -o push_swap
	cp push_swap ./push_swap_visualizer
	cd ./push_swap_visualizer

check : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) \
	-I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft \
	$(SRCS_CHECKER) $(SRCS_DO) -o checker

# python3 pyviz.py `ruby -e "puts (-20..20).to_a.shuffle.join(' ')"`
