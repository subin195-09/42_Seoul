/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:18:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/12 14:26:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *str_p;

	str_p = (char *)str;
	while (*str_p != c)
	{
		if (!*str_p)
			return (0);
		str_p++;
	}
	return (str_p);
}
