/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_in_fix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2021/02/17 17:19:34 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_dtoa_2_2(int i, char **rt, char **be_free)
{
	while (i >= 0)
	{
		if ((*rt)[i] == 58)
		{
			(*rt)[i] = '0';
			if (i > 1)
				(*rt)[i - 1]++;
			else
			{
				(*rt)[0] = '0';
				*be_free = ft_strjoin("1", *rt);
				free(*rt);
				*rt = *be_free;
			}
		}
		i--;
	}
}

static void			ft_dtoa_2(t_libset *set, double n, char **rt, char **be_free)
{
	int				i;
	double			db;

	db = (n < 0) ? -n : n;
	if (((*rt)[ft_strlen(*rt) - 1] == '.') && (set->flags.shap_flag != 1))
	{
		if (((int)(db * 10)) - (((int)db) * 10) > 5)
			(*rt)[ft_strlen(*rt) - 2]++;
		else if ((((int)(db * 10)) - (((int)db) * 10)) == 5)
		{
			if (((*rt)[ft_strlen(*rt) - 2] % 2 != 0))
				(*rt)[ft_strlen(*rt) - 2]++;
		}
		i = ft_strlen(*rt) - 2;
		ft_dtoa_2_2(i, rt, be_free);
		(*rt)[ft_strlen(*rt) - 1] = '\0';
	}
}

char				*ft_dtoa_in_fix(t_libset *set, double n, int pre, int wid)
{
	char			*rt;
	char			*be_free;
	long long		tmp1;
	double			db;

	if (n == 0)
		rt = ft_zero_maker(set, pre, wid);
	else
	{
		db = n - (long)n;
		tmp1 = n - db;
		be_free = ft_ltoa_no_minus(tmp1);
		rt = ft_strjoin(be_free, ".");
		free(be_free);
		if ((pre == 6) && (n == 0))
		{
			be_free = ft_strjoin(rt, "000000");
			free(rt);
			rt = be_free;
		}
		else if (pre >= 0)
			rt = ft_manti_to_a(set, db, rt, pre);
		ft_dtoa_2(set, n, &rt, &be_free);
	}
	return (rt);
}
