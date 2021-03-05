/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:53:49 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 18:17:58 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_frees(int size, ...)
{
	va_list var;
	int		i;

	va_start(var, size);
	i = 0;
	while (i < size)
	{
		if (va_arg(var, void*))
			free(va_arg(var, void*));
		i++;
	}
}
