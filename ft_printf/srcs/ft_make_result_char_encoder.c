/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_char_encoder.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:15:49 by skim              #+#    #+#             */
/*   Updated: 2020/10/28 05:16:07 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*uni_encoder_four(wint_t num)
{
	char	*result;
	int		i;

	i = 4;
	if (!(result = malloc(i)))
		return (0);
	result[i--] = '\0';
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 240 | num;
	return (result);
}

static char	*uni_encoder_three(wint_t num)
{
	char	*result;
	int		i;

	i = 3;
	if (!(result = malloc(i)))
		return (0);
	result[i--] = '\0';
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 224 | num;
	return (result);
}

static char	*uni_encoder_two(wint_t num)
{
	char	*result;
	int		i;

	i = 2;
	if (!(result = malloc(i)))
		return (0);
	result[i--] = '\0';
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 192 | num;
	return (result);
}

static char	*uni_encoder_one(wint_t num)
{
	char *result;

	if (!(result = malloc(2)))
		return (0);
	result[1] = '\0';
	result[0] = num;
	return (result);
}

char		*uni_encoder(wint_t num, int count_l, int *precision)
{
	char	*result;

	if (num < 128 || count_l != 1)
	{
		result = uni_encoder_one(num);
		*precision -= 1;
	}
	else if (num >= 128 && num <= 2047)
	{
		result = uni_encoder_two(num);
		*precision -= 2;
	}
	else if (num >= 2048 && num <= 65535)
	{
		result = uni_encoder_three(num);
		*precision -= 3;
	}
	else
	{
		result = uni_encoder_four(num);
		*precision -= 4;
	}
	return (result);
}
