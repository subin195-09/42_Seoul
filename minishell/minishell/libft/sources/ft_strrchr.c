/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:39:39 by spark             #+#    #+#             */
/*   Updated: 2020/10/06 12:05:47 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int tg)
{
	size_t len;

	len = ft_strlen(str);
	while (len != 0 && *(str + len) != tg)
		len--;
	if (*(str + len) == tg)
		return (char *)(str + len);
	return (NULL);
}
