/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:18:52 by skim              #+#    #+#             */
/*   Updated: 2020/09/30 16:18:53 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *temp;

	temp = (char *)str;
	while (*temp)
	{
		if (*temp == (unsigned char)c)
			return (temp);
		temp++;
	}
	return (0);
}
