/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:09 by spark             #+#    #+#             */
/*   Updated: 2021/05/09 15:37:51 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_key_val(char *str, char **key, char **value)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '=')
			break ;
	if (i > 0 && i < (int)(ft_strlen(str)))
	{
		*key = ft_strndup(str, i);
		*value = ft_strdup(str + i + 1);
		return (1);
	}
	else if (i == 0)
		return (-1);
	else
		return (-2);
}

int		check_equal(char *str, char **key, char **value)
{
	int		rt;

	if (!(ft_isalpha(str[0]) || (str[0] == '_')))
	{
		ft_putendl_fd("not a valid identifier", 2);
		g_ex.exit_code = -1;
		return (0);
	}
	rt = get_key_val(str, key, value);
	if (rt < 0)
	{
		if (rt == -1)
		{
			ft_putendl_fd("not a valid identifier", 2);
			g_ex.exit_code = -1;
		}
		return (0);
	}
	return (1);
}

void	cmd_export_change(char ***en, char *arg, char **key, char **value)
{
	char	*tmp;
	char	**new_en;

	tmp = find_env(*key, en);
	if (!tmp)
		new_en = add_env(en, arg);
	else
		new_en = update_env(en, arg, tmp);
	free(*key);
	free(*value);
	(*en) = new_en;
}

int		cmd_export(t_nd *com, char ***en, char *av)
{
	char	*key;
	char	*value;
	int		i;

	i = 0;
	if (!com->args[1])
	{
		export_print(*en);
		return (EXIT_SUCCESS);
	}
	while (com->args[++i])
	{
		if (check_equal(com->args[i], &key, &value))
			cmd_export_change(en, com->args[i], &key, &value);
	}
	if (g_ex.exit_code < 0)
		g_ex.exit_code = 1;
	else
		g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
	(void)av;
}
