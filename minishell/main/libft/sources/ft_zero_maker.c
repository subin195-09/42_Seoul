/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2021/02/17 17:20:41 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_zero_maker_2(t_libset *set, int wid)
{
	char	*be_free;
	char	*head_zero;
	char	*rt;

	rt = 0;
	head_zero = ft_strdup("0.");
	if ((wid > 0) && (set->flags.zeroflag == 1) && (set->flags.lefted == 0))
	{
		if (!(be_free = malloc(sizeof(char) * wid + 1)))
			return (0);
		ft_memset_chr(be_free, '0', wid + 1);
		be_free[wid] = 0;
		rt = ft_strdup(be_free);
		free(be_free);
	}
	else
		rt = ft_strdup("0");
	free(head_zero);
	return (rt);
}

char				*ft_zero_maker(t_libset *set, int pre, int wid)
{
	char	*be_free;
	char	*head_zero;
	char	*rt;

	rt = 0;
	head_zero = ft_strdup("0.");
	if ((set->flags.shap_flag == 1) && set->lenths.precision == 0)
		return (head_zero);
	if (pre == 0)
		return (ft_zero_maker_2(set, wid));
	else
	{
		if (!(be_free = malloc(sizeof(char) * pre + 1)))
			return (0);
		ft_memset_chr(be_free, '0', pre + 1);
		be_free[pre] = 0;
		rt = ft_strjoin_free(head_zero, be_free);
	}
	return (rt);
}
