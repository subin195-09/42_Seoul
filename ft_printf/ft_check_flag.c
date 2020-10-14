/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/10/15 04:43:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_flag(const char **format)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'L')
	{

	}
	else if (**format == ' ')
	{

	}
	else if (**format >= '0' && **format <= '9')
	{

	}
	else if (**format == '+')
	{

	}
	else if (**format == '.')
	{

	}
	else if (**format == '#')
	{

	}
	else
	{

	}
	return (count_bytes);
}
