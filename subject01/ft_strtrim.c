/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:26:49 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 15:22:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		start;
	int		end;

	if (!set && !s1)
		return (ft_strdup(""));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	if (!(result = malloc(end - start + 2)))
		return (0);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
