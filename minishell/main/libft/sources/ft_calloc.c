/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:10:23 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 15:34:22 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t many, size_t size)
{
	void *rt;

	rt = NULL;
	if (!(rt = malloc((size) * many)))
		return (0);
	ft_bzero(rt, size * many);
	return (rt);
}
