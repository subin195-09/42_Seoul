/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:24:47 by skim              #+#    #+#             */
/*   Updated: 2020/09/28 15:44:58 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelement, size_t bytes)
{
	void	*p;

	if (!(p = malloc(nelement * bytes)))
		return (0);
	if (p == 0)
		return (p);
	ft_bzero(p, nelement * bytes);
	return (p);
}
