/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:33:28 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 16:53:07 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIDE_OUT	0
#define SIDE_IN		1

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	0
#define TYPE_PIPE	1
#define TYPE_BREAK	2

typedef	struct	s_list
{
	char			**args;
	int				len;
	int				type;
	int				pipes[2];
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int		list_push(t_list **list, char *av);
int		list_rewind(t_list **list);
int		list_clear(t_list **cmds);
int		add_arg(t_list *cmd, char *av);

int		exit_fatal(void);
void	*exit_fatal_ptr(void);
int		show_error(char const *str);

int		exec_cmds(t_list **cmds, char **en);
