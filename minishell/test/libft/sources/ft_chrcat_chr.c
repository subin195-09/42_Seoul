/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcat_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:06:57 by spark             #+#    #+#             */
/*   Updated: 2021/04/11 21:15:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrcat_chr(unsigned char c1, unsigned char c2)
{
	char	*rt;
	char	*anchor;

	rt = malloc(sizeof(char) * 3);
	if (!rt)
		return (0);
	ft_memmove(rt, &c1, 1);
	anchor = rt;
	rt += 1;
	ft_memmove(rt, &c2, 1);
	anchor[2] = 0;
	return (anchor);
}
