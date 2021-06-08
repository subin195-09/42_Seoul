/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:33:28 by skim              #+#    #+#             */
/*   Updated: 2021/06/08 17:44:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	int		i;
	char	*dest;

	i = 0;
	size = ft_strlen(src);
	if (!(dest = malloc(size + 1)))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
	temp = n;
	temp = (temp >= 0) ? temp : -temp;
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