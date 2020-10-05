/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:47:27 by skim              #+#    #+#             */
/*   Updated: 2020/10/05 22:36:39 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	unsigned char	*s1_p;
	unsigned char	*s2_p;
	int				i;

	i = 0;
	s1_p = (unsigned char *)s1;
	s2_p = (unsigned char *)s2;
	while (i < n && (s1_p[i] || s2_p[i]))
	{
		if (s1_p[i] != s2_p[i])
			return (s1_p[i] - s2_p[i]);
		i++;
	}
	return (0);
}
