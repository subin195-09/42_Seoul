/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:09:47 by spark             #+#    #+#             */
/*   Updated: 2020/11/20 20:31:55 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		len;
	char	*rt;

	if (s1 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(rt = malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy(rt, s1, len);
	ft_strlcat(rt, s2, len);
	free(s1);
	free(s2);
	rt[len] = 0;
	return (rt);
}
