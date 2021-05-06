/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2021/05/05 22:28:13 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_array_round_3(char *str, int i)
{
	if (str[i] >= '5')
	{
		str[i - 1]++;
		str[i] = '\0';
	}
	else
		str[i] = '\0';
}

static void	ft_array_round_2(t_libset *set, char *str, int pre, int i)
{
	if (((set->f.s_bit.sgnfi) << (pre + 1 + \
	(set->f.s_bit.expond - 1023)) << 12) == 0)
	{
		if (str[i] > '5')
		{
			str[i - 1]++;
			str[i] = '\0';
		}
		else if (str[i] == '5')
		{
			if ((str[i - 1] % 2) != 0)
			{
				str[i - 1]++;
			}
			str[i] = '\0';
		}
		else
			str[i] = '\0';
	}
	else
		ft_array_round_3(str, i);
}

char		ft_array_round(t_libset *set, char *str, int pre)
{
	int	len;
	int	i;

	i = (int)ft_strlen(str);
	while ((int)ft_strlen(str) > pre + 1)
		str[--i] = '\0';
	len = ft_strlen(str);
	i = len - 1;
	i = (i < 0) ? 0 : i;
	ft_array_round_2(set, str, pre, i--);
	while (i > 0)
	{
		if (str[i] == 58)
		{
			str[i] = '0';
			str[i - 1]++;
		}
		i--;
	}
	if (str[0] == 58)
	{
		str[i] = '0';
		return (1);
	}
	return (0);
}
