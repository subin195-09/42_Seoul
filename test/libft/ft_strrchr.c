/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:22:24 by skim              #+#    #+#             */
/*   Updated: 2020/10/02 16:23:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_p;
	int		i;

	str_p = (char *)str;
	i = ft_strlen(str);
	if ((char)c == 0)
		return (str_p + i);
	while (i--)
	{
		if (str_p[i] == (char)c)
			return (&str_p[i]);
	}
	return (0);
}
