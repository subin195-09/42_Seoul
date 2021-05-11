/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:16:24 by spark             #+#    #+#             */
/*   Updated: 2021/05/05 15:15:53 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t d_i;
	size_t s_i;

	d_i = 0;
	s_i = 0;
	while (dest[d_i])
		d_i++;
	while (src[s_i])
		dest[d_i++] = src[s_i++];
	dest[d_i] = 0;
	return (dest);
}
