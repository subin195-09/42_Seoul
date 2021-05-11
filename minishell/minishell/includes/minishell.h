/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:19 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:07:29 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>

# define BLT_NUM	7
# define SEP		"\t\n\r\a "

# define TYPE_NONE	-1
# define TYPE_C_P	1

# define RE_TYPE_OUT	1
# define RE_TYPE_OOUT	2
# define RE_TYPE_IN		3

# define SIDE_OUT	0
# define SIDE_IN	1

# define STDOUT		1
# define STDIN		0

typedef struct	s_exit_code
{
	int		exit_code;
	int		is_signaled;
	pid_t	pid;
}				t_exit_code;

typedef struct	s_hist
{
	char			*content;
	struct s_hist	*next;
	struct s_hist	*prev;
	int				count;
}				t_hist;

typedef struct	s_red
{
	int		rdrt_type;
	int		rdrt_in_type;
	char	*rdrt_name;
	char	*rdrt_in_name;
	int		rdrt_fd;
	int		rdrt_in_fd;
}				t_red;

typedef struct	s_nd
{
	char			**args;
	struct s_nd		*child;
	struct s_nd		*sible;
	struct s_nd		*prev;
	int				type;
	int				pipes[2];
	t_red			re;
}				t_nd;

t_exit_code		g_ex;
int				start_shell(char ***en, char *av);
int				synerror_checker(char *args, char a);
int				synerror_redirect(char *arg);
char			**split_quote(char *str, char *set);
char			**split_redirect(char **b_arg);

t_nd			*big_cutter(char *str);
int				lexer(t_nd *new, char *args);
int				tokenizer(t_nd *nd);
int				token_changer(t_nd *nd, char ***en);

int				env_except_none\
				(char *args, int *arg_i, char *cpy_arg, char ***en);
int				env_except_qoute\
				(char *args, int *arg_i, char *cpy_arg, char ***en);
int				env_changer(char *args, int *arg_i, char *cpy_arg, char ***en);

int				get_redirect(t_nd *nd, char **en);
int				get_redirect_info(t_nd *nd, int arg_count);

int				run(t_nd *cmd, char ***en, char *av);
int				check_red_name(t_nd *cmd);
int				pipe_dup(t_nd *cmd);
void			pipe_close(t_nd *cmd);

int				builtin_run(t_nd *cmd, char ***en, char *av, int i);
char			*blt_str(int i);
int				(*g_blt_func(int i))(t_nd *cmd, char ***en, char *av);

void			find_cmd(t_nd *com, char ***en, char *av);
int				execute_ps(char *run_com, t_nd *com, char **en);

int				cmd_exit(t_nd *com, char ***en, char *name);
int				cmd_env(t_nd *com, char ***en, char *av);
int				cmd_cd(t_nd *com, char ***en, char *av);
int				cmd_pwd(t_nd *com, char ***en, char *av);
int				cmd_unset(t_nd *com, char ***en, char *av);
int				cmd_export(t_nd *com, char ***en, char *av);
int				export_print(char **en);
int				cmd_echo(t_nd *com, char ***en, char *av);

char			*find_env(char *key, char ***en);
char			*find_env_val(char *key, char ***en);
char			**add_env(char ***en, char *str);
char			**update_env(char ***en, char *str, char *find_en);
char			**delete_env(char ***en, char *find_en);

t_nd			*new_nd(char *name);
t_nd			*child_rewind(t_nd *coms);
void			print_list(t_nd *com);

int				matrix_line_num(char **matrix);
int				is_bslash(char *s, int i);
void			check_quote(char *s, int i, int *q_f, int *qq_f);

void			*signal_ctlc(int signo);
void			*signal_ctlslash(int signo);

t_hist			*history_add(t_hist *nd);
void			print_list_2(t_hist *com);
char			*get_ch(t_hist	*nd);
int				is_redirect(char *str);
void			free_nd(t_nd *coms);
void			free_hist(t_hist *hist);
void			start_write(void);
int				run_cmd(t_nd *coms, char ***en, char *av);
void			get_ch_up_down(t_hist **nd, char c[2], t_hist **anc);
void			get_ch_erase(t_hist *nd);
void			get_ch_ctld(t_hist **anc, t_hist **nd, char c[2]);
void			free_matrix(char ***matrix);
int				cmd_pwd_update(char **o_key, char **o_val, \
								char **old, char ***en);
void			cmd_cd_error(t_nd *com, int rt);
void			execute_satus(void);
void			make_dup(int *fd, int type);

#endif
