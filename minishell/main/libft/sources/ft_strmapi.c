/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 19:17:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 22:12:00 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rt;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (!(rt = malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		rt[i] = f(i, s[i]);
		i++;
	}
	rt[len] = '\0';
	return (rt);
}
