/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:46:49 by skim              #+#    #+#             */
/*   Updated: 2020/11/30 20:52:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_num_ulong(unsigned long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_ultoa(unsigned long long n)
{
	char				*result;
	int					count;

	if (n == 0)
		return (ft_strdup("0"));
	count = count_num_ulong(n);
	if (!(result = malloc(count + 1)))
		return (0);
	result[count--] = '\0';
	while (n > 0)
	{
		result[count--] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
