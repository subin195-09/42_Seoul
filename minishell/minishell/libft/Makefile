NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HDER = ./includes/libft.h
RM = rm -f

B_SRCS = $(addprefix ./sources/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c)

SRCS = $(addprefix ./sources/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strchrs.c ft_memset_chr.c \
		ft_int_len.c ft_itoa_no_minus.c ft_ltoa.c ft_convert_base_u.c ft_convert_base.c ft_is_space.c ft_print_memory.c ft_strcat_chr.c ft_ltoa_no_minus.c ft_chrcat_chr.c ft_memmove_f.c ft_ultoa.c \
		ft_ltoa_no_minus_round.c ft_free_va.c ft_strjoin_free.c ft_db_len.c ft_power.c ft_zero_maker.c ft_manti_to_a.c ft_array_round.c \
		ft_ilencal.c ft_get_next_line.c ft_strcmp.c ft_strcat.c)

ALLSRCS = $(addprefix ./sources/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_strchrs.c \
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_memset_chr.c \
		ft_int_len.c ft_itoa_no_minus.c ft_ltoa.c ft_convert_base_u.c ft_convert_base.c ft_is_space.c ft_print_memory.c ft_strcat_chr.c ft_ltoa_no_minus.c ft_chrcat_chr.c ft_memmove_f.c ft_ultoa.c \
		ft_ltoa_no_minus_round.c ft_free_va.c ft_strjoin_free.c ft_db_len.c ft_power.c ft_zero_maker.c ft_manti_to_a.c ft_array_round.c \
		ft_ilencal.c ft_get_next_line.c ft_strcmp.c ft_strcat.c)

ALLOBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(ALLSRCS:.c=.o)))
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
B_OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(B_SRCS:.c=.o)))
HDER_DIR = ./includes
OBJ_DIR = ./objects
SRC_DIR = ./sources
AR = ar rc

all : $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(HDER_DIR) -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p objects

$(NAME) : $(OBJS)
	@$(AR) $(NAME) $(OBJS)

bonus : $(ALLOBJS)
	@$(AR) $(NAME) $(ALLOBJS)
clean :
	@($(RM) $(OBJS) $(B_OBJS))
fclean : clean
	@($(RM) $(NAME))
re : fclean all
