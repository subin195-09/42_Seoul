/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_va.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:10:23 by spark             #+#    #+#             */
/*   Updated: 2020/11/02 13:18:36 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_va(int cnt, ...)
{
	void	*be_free;
	int		i;
	va_list	l;

	i = 0;
	va_start(l, cnt);
	be_free = 0;
	while (i < cnt)
	{
		be_free = va_arg(l, void*);
		if (be_free != 0)
			free(be_free);
		i++;
	}
	va_end(l);
}
