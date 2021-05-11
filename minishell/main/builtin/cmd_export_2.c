/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:06 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:53:25 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	trans_env(char **en, int num)
{
	int		i;
	int		j;
	int		min;
	char	*tmp;

	i = -1;
	j = -1;
	min = 0;
	while (++i < num)
	{
		j = i;
		min = i;
		while (++j < num)
		{
			if (ft_strcmp(en[i], en[j]) >= 0)
			{
				tmp = ft_strdup(en[i]);
				free(en[i]);
				en[i] = ft_strdup(en[j]);
				free(en[j]);
				en[j] = ft_strdup(tmp);
				free(tmp);
			}
		}
	}
}

void	export_print_2(char *tmp_en)
{
	int	j;

	j = -1;
	printf("declare -x ");
	while (tmp_en[++j])
	{
		printf("%c", tmp_en[j]);
		if (tmp_en[j] == '=')
			printf("\"");
	}
	printf("\"\n");
}

int		export_print(char **en)
{
	int		i;
	int		num;
	char	**tmp_en;

	i = -1;
	num = matrix_line_num(en);
	tmp_en = malloc(sizeof(char*) * (num + 1));
	if (!tmp_en)
		return (0);
	while (++i < num)
		tmp_en[i] = ft_strdup(en[i]);
	tmp_en[i] = 0;
	i = -1;
	trans_env(tmp_en, num);
	while (en[++i])
	{
		export_print_2(tmp_en[i]);
		free(tmp_en[i]);
	}
	free(tmp_en);
	return (EXIT_SUCCESS);
}
