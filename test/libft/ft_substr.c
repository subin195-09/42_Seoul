/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:34:34 by skim              #+#    #+#             */
/*   Updated: 2020/10/02 16:30:50 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (!s || !len)
		return (0);
	s_len = ft_strlen(s);
	if (start + len > s_len)
		return (ft_strdup(""));
	if (!(substr = malloc(len + 1)))
		return (0);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
