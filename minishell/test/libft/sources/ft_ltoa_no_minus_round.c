/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_no_minus_round.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:34:40 by spark             #+#    #+#             */
/*   Updated: 2020/11/09 15:54:59 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*make_six_pre(int len, char *str)
{
	int		zero_len;
	char	*tmp;

	zero_len = 6 - len;
	if (!(tmp = malloc(sizeof(char) * 6)))
		return (0);
	tmp = ft_memset_chr(tmp, '0', 6);
	ft_memmove(tmp + zero_len, str, ft_strlen(str));
	free(str);
	return (tmp);
}

static int		ilencal(int n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

char			*ft_ltoa_no_minus_round(long long n)
{
	char			*rt;
	double			tmp;
	long long		tmp_int;
	double			tmp2;
	long long		int_len;

	if (n < 0)
		tmp = (double)-n;
	else
		tmp = (double)n;
	tmp2 = tmp / 10;
	tmp_int = (long long)(tmp / 10);
	tmp2 = tmp2 - (long long)(tmp / 10);
	if (tmp2 >= 0.5)
		tmp_int += 1;
	int_len = ilencal(tmp_int);
	rt = ft_ltoa_no_minus(tmp_int);
	if (int_len < 6)
		rt = make_six_pre(int_len, rt);
	return (rt);
}
