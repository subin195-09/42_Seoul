/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manti_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2021/02/17 17:21:21 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_manti_to_a_3_2(t_libset *set, char **base)
{
	if (ft_strlen(*base) > 2)
	{
		(*base)[2] = 0;
		(*base)[1] = '.';
		if (set->flags.shap_flag == 0)
			set->e_expond++;
	}
}

static void	ft_manti_to_a_3(t_libset *set, char **base, int i)
{
	char	*be_free;

	be_free = 0;
	(*base)[i]++;
	while (i >= 0)
	{
		if (((*base)[i] == 58) && (i > 0))
		{
			(*base)[i] = '0';
			(*base)[i - 1]++;
		}
		if ((*base)[0] == 58)
		{
			(*base)[0] = '0';
			be_free = ft_strjoin("1", *base);
			free(*base);
			*base = be_free;
		}
		i--;
	}
	if ((set->type == 'e') || (set->type == 'E'))
		ft_manti_to_a_3_2(set, base);
}

static void	ft_manti_to_a_2_2(char **rt)
{
	if ((*rt)[0] != '\0')
		*rt = ft_strcat_chr(*rt, '0');
	else
		(*rt)[0] = '0';
}

static int	ft_manti_to_a_2(char **rt, double manti, int pre)
{
	int		i;
	int		tmp_int;
	double	tmp_db;
	char	*be_free;

	i = -1;
	tmp_int = 0;
	while (++i < pre + 1)
	{
		tmp_db = manti * 10;
		if ((int)tmp_db == (int)manti)
			ft_manti_to_a_2_2(rt);
		manti = tmp_db;
		tmp_int = (long long)manti;
		if (ft_ilencal(tmp_int) == 5)
		{
			be_free = ft_ltoa_no_minus(tmp_int);
			*rt = ft_strjoin_free(*rt, be_free);
			manti = manti - (long long)manti;
			tmp_int = 0;
		}
	}
	return (tmp_int);
}

char		*ft_manti_to_a(t_libset *set, double manti, char *base, int pre)
{
	int		i;
	char	*rt;
	char	*be_free;
	int		tmp_int;

	i = 0;
	be_free = 0;
	tmp_int = 0;
	manti = (manti < 0) ? -manti : manti;
	if (!(rt = malloc(sizeof(char) * 2)))
		return (0);
	rt[0] = '\0';
	rt[1] = '\0';
	if (pre > 0)
		tmp_int = ft_manti_to_a_2(&rt, manti, pre);
	be_free = ft_ltoa_no_minus(tmp_int);
	rt = ft_strjoin_free(rt, be_free);
	i = ft_strlen(base) - 2;
	if (ft_array_round(set, rt, pre))
		ft_manti_to_a_3(set, &base, i);
	rt = ft_strjoin_free(base, rt);
	return (rt);
}
