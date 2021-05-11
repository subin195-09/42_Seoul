/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:45:30 by spark             #+#    #+#             */
/*   Updated: 2021/02/17 17:20:01 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_db_len(t_libset *set, double n, int pre, int wid)
{
	char	*tmp;
	int		rt;

	tmp = ft_dtoa_in_fix(set, n, pre, wid);
	rt = ft_strlen(tmp);
	free(tmp);
	return (rt);
}
