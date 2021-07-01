NAME = megaphone

CC = clang++
CFLAGS = -Wall -Werror -Wextra

SRCS = megaphone.cpp

all : $(NAME)

$(NAME) : 
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
	@rm -rf $(NAME)

fclean : clean

re : fclean all