/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:33:28 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:30:48 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int		count_num(int n)
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

char	*ft_itoa(int n)
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

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (size--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	free(s2);
	return (str);
}
