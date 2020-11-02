/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:21:58 by skim              #+#    #+#             */
/*   Updated: 2020/11/01 21:09:48 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		round_double(int num2)
{
	int	temp;

	temp = num2 % 10;
	if (temp > 5)
		num2 += 10;
	return (num2 / 10);
}

int		change_int(double num2, int size)
{
	int		count;

	count = 0;
	while (count < size + 1)
	{
		num2 *= (double)10;
		count++;
	}
	return (round_double((int)num2));
}

char	*ft_dtoa(double num, int size)
{
	char	*result;
	char	*num1_char;
	char	*num2_char;
	int		num1;
	int		num2;

	num1 = num;
	num2 = change_int(num - num1, size + 1);
	num2 = round_double(num2);
	num1_char = ft_itoa(num1);
	num2_char = ft_strjoin(".", ft_itoa(num2));
	result = ft_strjoin(num1_char, num2_char);
	free(num1_char);
	free(num2_char);
	num1_char = 0;
	num2_char = 0;
	return (result);
}

int main(void)
{
	double d = 10.135;
	int size = 2;

	printf("%.*f\n", size, d);
	printf("%s\n", ft_dtoa(d, size));
}
