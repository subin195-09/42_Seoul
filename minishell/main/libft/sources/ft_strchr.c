/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:23:33 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 21:07:26 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int tg)
{
	while (*str != (unsigned char)tg)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (char *)str;
}
