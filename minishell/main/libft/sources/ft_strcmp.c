/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:17:21 by spark             #+#    #+#             */
/*   Updated: 2021/05/05 21:09:32 by spark            ###   ########.fr       */
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
