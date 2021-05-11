/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:40:49 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/03 12:09:42 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_chr(char *s1, char c)
{
	int		len;
	char	*rt;

	if (s1 == NULL)
		return (0);
	len = ft_strlen(s1);
	if (!(rt = malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memmove(rt, (char*)s1, ft_strlen(s1));
	rt[len] = c;
	rt[len + 1] = 0;
	free(s1);
	return (rt);
}
