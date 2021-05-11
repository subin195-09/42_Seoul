/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcat_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 01:06:57 by spark             #+#    #+#             */
/*   Updated: 2020/11/09 15:57:34 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrcat_chr(unsigned char c1, unsigned char c2)
{
	char	*rt;
	char	*anchor;

	if (!(rt = malloc(sizeof(char) * 3)))
		return (0);
	ft_memmove(rt, &c1, 1);
	anchor = rt;
	rt += 1;
	ft_memmove(rt, &c2, 1);
	anchor[2] = 0;
	return (anchor);
}
