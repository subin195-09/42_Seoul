/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:27:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/23 19:36:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			make_result_uint(t_info info, va_list var)
{
	char			*result;
	unsigned int	num;

	num = va_arg(var, unsigned int);
}
