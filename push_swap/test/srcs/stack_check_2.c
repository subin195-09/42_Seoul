/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 20:43:22 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 20:43:42 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		is_int(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		check_int(char *av_split, long long *num)
{
	if (!is_int(av_split))
		return (0);
	(*num) = ft_atol(av_split);
	if (*num > INT_MAX || *num < INT_MIN)
		return (0);
	return (1);
}
