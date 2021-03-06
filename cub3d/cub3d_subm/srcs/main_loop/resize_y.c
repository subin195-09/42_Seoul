/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:21:40 by skim              #+#    #+#             */
/*   Updated: 2021/03/04 16:31:29 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		make_re_y(t_set *set, int y)
{
	if (y < 1)
		return (0);
	else if (y > set->minfo.s_height - 2)
		return (set->minfo.s_height);
	else
		return (y);
}
