/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:22:24 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 15:19:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_p;
	int		i;

	str_p = (char *)str;
	i = ft_strlen(str);
	if (c == 0)
		return (str_p + i);
	while (i--)
	{
		if (str_p[i] == c)
			return (&str_p[i]);
	}
	return (0);
}
