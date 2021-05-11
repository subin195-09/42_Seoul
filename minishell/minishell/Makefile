NAME = minishell
LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INC_DIR = ./includes
LIB_DIR = ./libft
SRCS_DIR = ./srcs
BLT_DIR = ./builtin

SRCS =	\
	./srcs/ascii_art.c	\
	./srcs/big_cutter.c	\
	./srcs/free_memory.c	\
	./srcs/get_ch.c	\
	./srcs/get_ch_2.c	\
	./srcs/get_redirect.c	\
	./srcs/get_redirect_info.c	\
	./srcs/history.c	\
	./srcs/lexer.c	\
	./srcs/main.c	\
	./srcs/run.c	\
	./srcs/run_built.c	\
	./srcs/run_cmd.c	\
	./srcs/run_inner.c	\
	./srcs/signal_care.c	\
	./srcs/split_quote.c	\
	./srcs/split_redirect.c	\
	./srcs/start_shell.c	\
	./srcs/syntax_checker.c	\
	./srcs/token_changer.c	\
	./srcs/token_changer_2.c	\
	./srcs/utils.c	\
	./srcs/utils_2.c	\
	./builtin/change_envp.c	\
	./builtin/cmd_cd.c	\
	./builtin/cmd_cd_2.c	\
	./builtin/cmd_echo.c	\
	./builtin/cmd_env.c	\
	./builtin/cmd_exit.c	\
	./builtin/cmd_export.c	\
	./builtin/cmd_export_2.c	\
	./builtin/cmd_pwd.c	\
	./builtin/cmd_unset.c	\
	./builtin/find_envp.c


all : $(NAME)

$(NAME) : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) \
	-L ./$(LIB_DIR) -lft -o $(NAME) $(SRCS)

$(LIB_DIR)/$(LIBFT) :
	@make -C $(LIB_DIR)

re : fclean all

clean :
	@rm -rf $(NAME)
	@make -C $(LIB_DIR) clean

fclean : clean
	@rm -rf $(LIBFT)
	@make -C $(LIB_DIR) fclean

test : $(LIB_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -L ./$(LIB_DIR) -lft $(SRCS)
	@./a.out
	@rm a.out

.PHONY : test
