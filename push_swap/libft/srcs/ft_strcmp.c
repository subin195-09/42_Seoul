/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 01:07:59 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 01:08:00 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				max;
	int				i;
	unsigned char	str1;
	unsigned char	str2;

	i = -1;
	if (ft_strlen(s1) > ft_strlen(s2))
		max = ft_strlen(s1);
	else
		max = ft_strlen(s2);
	while (++i < max)
	{
		str1 = s1[i];
		str2 = s2[i];
		if (str1 != str2)
			return (str1 - str2);
		if (str1 == '\0')
			return (0);
	}
	return (0);
}
