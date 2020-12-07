/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:26:12 by skim              #+#    #+#             */
/*   Updated: 2020/12/08 00:00:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef	struct		s_info
{
	int		width;
	int		precision;
}					t_info;

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*result;
	int		i = 0;

	if (!(result = malloc(ft_strlen(s) + 1)))
		return (0);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int		count_num(unsigned int num, int base_len)
{
	int i = 0;

	if (num == 0)
		return (1);
	while (num)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

char	*base(char *base, unsigned int num)
{
	char	*ret;

	int base_len = ft_strlen(base);
	int i = count_num(num, base_len);
	if (!(ret = malloc(i + 1)))
		return (0);
	base[i--] = 0;
	if (num == 0)
		ret[i] = base[0];
	while (num)
	{
		base[i--] = base[num % base_len];
		num /= base_len;
	}
	return (ret);
}

int		make_result_string(t_info info, va_list ap)
{
	char	*s = va_arg(ap, char *);
	char	*result;
	char	*body;
	int		i = 0;

	if (!s)
		s = "(null)";
	if (info.precision > -1 && info.precision < ft_strlen(s))
	{
		if (!(body = malloc(info.precision + 1)))
			return (0);
		body[info.precision] = 0;
		for(i = 0; i < info.precision; i++)
			body[i] = s[i];
	}
	else
		body = ft_strdup(s);
	if (info.width > ft_sttrlen(body))
	{
		if (!(result = malloc(info.width + 1)))
			return (0);
		for (i = 0; i < info.width; i++)
			result[i] = ' ';
		result[i] = 0;
		for (int j = ft_strlen(body); j >= 0; j--)
		   result[i--] = body[j];
	}
	else
		result = ft_strdup(body);
	i = write(1, result, ft_strlen(result));
	free(result);
	free(body);
	return (ret);
}

int		make_result(char **format, t_info *info, va_list ap)
{
	int ret = 0;
	if (**format == 'd')
		ret = make_result_int(*info, ap);
	else if (**format == 'x')
		ret = make_result_base(*info, ap);
	else if (**format == 's')
		ret = make_result_string(*info, ap);
	(*format)++;
	return (ret);
}

void	init_info(t_info *info)
{
	info->width = 0;
	info->precision = -1;
}

int		check_type(char c)
{
	if (c == 'x')
		return (0);
	else if (c == 'd')
		return  (0);
	else if (c == 's')
		return (0);
	else
		return (1);
}

int		check_format(char **format, va_list ap)
{
	s_info	info[1];
	int		ret = 0;

	init_info(info);
	while (**format && check_type(**format))
	{
		if (**format == '.')
		{
			(*format)++;
			info.precision = ft_atoi(*format);
			(*format) += count_num(info.precision);
		}
		else if (**format >= '0' && **format <= '9')
		{
			info.width = ft_atoi(*format);
			(*format) += count_num(info.width);
		}
		else
			(*format)++;
	}
	ret = make_result(format, info, ap);
	return (ret);
}

int		ft_printf(const char *format, ... )
{
	va_list	ap;
	int ret = 0;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ret += write(1, format, 1);
		else
			ret += check_format(&foramt, ap);
	}
	va_end(ap);
	return (ret);
}
