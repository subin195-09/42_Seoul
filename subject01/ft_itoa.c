/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:28:41 by skim              #+#    #+#             */
/*   Updated: 2020/09/30 15:23:21 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char		*result;
	long long	temp;
	int			count;
	int			sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = (n >= 0) ? n : -n;
	sign = (n >= 0) ? 0 : 1;
	count = count_num(n);
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
