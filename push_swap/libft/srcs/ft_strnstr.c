/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:16:41 by skim              #+#    #+#             */
/*   Updated: 2020/10/04 17:48:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i] == little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)&big[i - j]);
		i = i - j + 1;
	}
	return (0);
}
