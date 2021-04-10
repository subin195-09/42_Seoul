/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:40:27 by skim              #+#    #+#             */
/*   Updated: 2021/04/10 17:21:34 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <libft.h>
# include <string.h>
# include <get_next_line.h>

# define BLT_NUM 2

int		start_shell(char **en, char *av);
char	**make_tok(char *str, char *charset);
int		run(char **run_com, char **en, char *av);

int		cmd_exit(char **run_com, char **en, char *name);
int		cmd_env(char **run_com, char **en, char *av);

#endif
