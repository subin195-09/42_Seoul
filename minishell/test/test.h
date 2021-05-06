#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "libft/includes/libft.h"
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <termios.h>

# define BLT_NUM 2

# define TYPE_NONE	-1
# define TYPE_NONE	-1
# define TYPE_C_P 	1
# define TYPE_P_C 	2
# define TYPE_RE  	3

typedef struct s_red
{
	int		rdrt_yn;
	int		rdrt_fd;
} t_red;;

typedef struct 	s_info
{
	struct s_nd		*head;
	struct s_nd		*tail;
}				t_info;

typedef struct 	s_nd
{
	char			**args;
	struct s_nd		*child;
	struct s_nd		*sible;
	struct s_nd		*prev;
	int				type;
	int				pipes[2];

	t_info			pos;
	t_red			re;
}				t_nd;

int		start_shell(char **en, char *av);
char	**make_tok(char *str, char *charset);
int		run(char **run_com, char **en, char *av);

int		cmd_exit(char **run_com, char **en, char *name);
int		cmd_env(char **run_com, char **en, char *av);
char	*find_env(char *key, char **en);

#endif
