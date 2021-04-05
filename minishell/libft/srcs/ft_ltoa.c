/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:45:55 by skim              #+#    #+#             */
/*   Updated: 2020/10/27 02:05:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_num_long(long long n)
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

char		*ft_ltoa(long long n)
{
	char				*result;
	unsigned long long	temp;
	int					count;
	int					sign;

	if (n == 0)
		return (ft_strdup("0"));
	temp = n >= 0 ? n : -n;
	sign = n >= 0 ? 0 : 1;
	count = count_num_long(n);
	if (!(result = malloc(sign + count + 1)))
		return (0);
	if (sign)
		result[0] = '-';
	result[sign + count--] = '\0';
	while (temp > 0)
	{
		result[sign + count--] = temp % 10 + '0';
		temp /= 10;
	}
	return (result);
}
