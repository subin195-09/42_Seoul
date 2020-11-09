/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_per.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:26:16 by skim              #+#    #+#             */
/*   Updated: 2020/10/24 17:37:13 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result_per(t_info info)
{
	char	*result;
	char	padding;
	int		len;
	int		count_bytes;

	len = info.width > 1 ? info.width : 1;
	padding = info.left != 0 ? ' ' : info.padding;
	if (!(result = malloc(sizeof(len) + 1)))
		return (0);
	result[len] = '\0';
	ft_memset(result, padding, len);
	if (info.left)
		result[0] = '%';
	else
		result[len - 1] = '%';
	count_bytes = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (count_bytes);
}
