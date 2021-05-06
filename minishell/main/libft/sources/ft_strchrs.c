/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:43:05 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 10:48:52 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrs(const char *str, char *to_find)
{
	size_t i;

	i = 0;
	while (*to_find)
	{
		while (str[i] != (unsigned char)*to_find)
		{
			if (str[i] == '\0')
				return (0);
			else if (str[i] == *to_find)
				return ((char*)&str[i]);
			i++;
		}
		to_find++;
		i = 0;
	}
	return (0);
}
