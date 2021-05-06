/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:10:23 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 21:14:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t many, size_t size)
{
	void	*rt;

	rt = NULL;
	rt = malloc((size) *many);
	if (rt == 0)
		return (0);
	ft_bzero(rt, size * many);
	return (rt);
}
