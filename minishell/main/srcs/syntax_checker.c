/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:17 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:48:43 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_file_name(char *arg)
{
	int	i;

	i = 1;
	while (arg[i] && ft_strchr(SEP, arg[i]))
		i++;
	if (arg[i] == '>' || arg[i] == '<' || !arg[i])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		synerror_redirect(char *arg)
{
	int	qq_f;
	int	q_f;
	int	i;

	qq_f = 1;
	q_f = 1;
	i = -1;
	if (!arg || !*arg)
		return (EXIT_SUCCESS);
	while (arg[++i])
	{
		check_quote(arg[i], &q_f, &qq_f);
		if (q_f > 0 && qq_f > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			if (arg[i + 1] == '>')
				i++;
			if (find_file_name(&arg[i]) == EXIT_FAILURE)
			{
				g_ex.exit_code = 258;
				printf("redirection : syntax error\n");
				return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

void	synerror_qoute(char c, int *q_f, int *qq_f)
{
	if (c == '\"')
	{
		if (*q_f > 0)
			*qq_f *= -1;
	}
	else if (c == '\'')
	{
		if (*qq_f > 0)
			*q_f *= -1;
	}
}

int		synerror_checker_2(char *args, char a, int *q_f, int *qq_f)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		synerror_qoute(args[i], q_f, qq_f);
		if ((args[i] == a) && *qq_f > 0 && *q_f > 0)
		{
			i++;
			while (args[i] == ' ')
				i++;
			if (args[i] == a || (!args[i] && a == '|'))
				return (-1);
		}
	}
	return (1);
}

int		synerror_checker(char *args, char a)
{
	int		i;
	int		q_f;
	int		qq_f;

	q_f = 1;
	qq_f = 1;
	i = 0;
	if (!args)
		return (EXIT_SUCCESS);
	while (args[i] && ft_strchr(SEP, args[i]))
		i++;
	if (args[i] == a || synerror_checker_2(args, a, &q_f, &qq_f) < 0)
	{
		g_ex.exit_code = 258;
		printf("%c : syntax error\n", a);
		return (-1);
	}
	if (qq_f == -1 || q_f == -1)
	{
		printf("minishell : quote error\n");
		g_ex.exit_code = 258;
		return (-1);
	}
	return (EXIT_SUCCESS);
}
