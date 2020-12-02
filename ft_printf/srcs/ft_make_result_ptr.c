/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:40:04 by skim              #+#    #+#             */
/*   Updated: 2020/12/02 15:32:45 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*cut_and_paste_p(t_info info, long long num)
{
	char	*result;
	char	*hex_num;
	char	*with_pre;
	char	*temp;

	hex_num = (info.precision == 0 && num == 0) ? \
	ft_strdup("") : change_base(num, "0123456789abcdef");
	if (info.precision > -1 && info.precision > (int)ft_strlen(hex_num))
	{
		with_pre = base_precision(hex_num, info);
		temp = ft_strjoin("0x", with_pre);
		free(with_pre);
		with_pre = 0;
	}
	else
		temp = ft_strjoin("0x", hex_num);
	if (info.width > (int)ft_strlen(temp))
		result = cut_and_paste_base(temp, info, 'p');
	else
		result = ft_strdup(temp);
	free(hex_num);
	free(temp);
	hex_num = 0;
	temp = 0;
	return (result);
}

int			make_result_p(t_info info, va_list var)
{
	char			*result;
	unsigned char	*temp;
	void			*ptr;
	int				count_bytes;

	ptr = va_arg(var, void*);
	temp = (unsigned char*)ptr;
	result = cut_and_paste_p(info, (long long)temp);
	count_bytes = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (count_bytes);
}
