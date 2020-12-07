#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_num(int num)
{
	if (num == 0)
		return (1);
	int i = 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	return (i);
}

int count_base(int base_len, unsigned int num)
{
	if (num == 0)
		return (1);
	int i = 0;
	while (num)
	{
		num /= base_len;
		i++;
	}
	return (i);
}
//#include <stdio.h>
char *ch_base(char *base, unsigned int num)
{
	int base_len = ft_strlen(base);
	char *ret;

	int i = count_base(base_len, num);
	if (!(ret = malloc(i + 1)))
		return (0);
	ret[i--] = 0;
	if (num == 0)
		ret[i--] = base[0];
	while (i >= 0)
	{;
		ret[i--] = base[num % base_len];
		num /= base_len;
	}
//	printf("%s\n", ret);
	return (ret);
}

char *ft_strdup(char *s)
{
	int i = ft_strlen(s);
	char *ret;

	if (!(ret = malloc(i + 1)))
		return (0);
	ret[i] = 0;
	int j = 0;
	while (s[j])
	{
		ret[j] = s[j];
		j++;
	}
	return  (ret);
}


char *ft_strndup(char *s, int n)
{
	int i = 0;
	char *ret;

	if (!(ret = malloc(n + 1)))
		return (0);
	ret[n] = 0;
	for(i = 0; i < n; i++)
		ret[i] = s[i];
	return (ret);
}

int make_result_str(va_list ap, int width,  int precision)
{
	int size;
	char *str = va_arg(ap, char *);

//	write(1, str, ft_strlen(str));
	if (!str)
		str = "(null)";
	//write(1, str, ft_strlen(str));
	size = ft_strlen(str);
	if (precision > -1)
		size = size < precision ? size : precision;
	char *temp = ft_strndup(str, size);
	char *result;
	if (width > size)
	{
		if (!(result = malloc(width + 1)))
			return (0);
		result[width] = 0;
		for (int i = 0; i < width; i++)
		result[i] = ' ';
		if (precision > 0 && size > width)
			while (size >= 0)
				result[--width] = temp[--size];

	}
	else
		result = ft_strdup(temp);
	size = write(1, result, ft_strlen(result));
	free(temp);
	free(result);
	return (size);
}
int zero_check(int width)
{
	int ret = 0;

	if (width > 0)
		ret += write(1, " ", 1);
	return (ret);
}

int make_result_base(va_list ap, int width, int precision)
{
	unsigned int num = va_arg(ap, unsigned int);
	if (num == 0 && precision == 0)
		return (zero_check(width));
	char *base = ch_base("0123456789abcdef", num);
	int size = ft_strlen(base);
	//write(1, base, size);
	if (precision > -1)
		size = precision > size ? precision : size;
	int back = size;
	char temp[size + 1];
	temp[size] = 0;
	for(int i = 0; i < size; i++)
		temp[i] = '0';
	int j = ft_strlen(base);
	while (j >= 0)
		temp[--size] = base[--j];
	char *result;
	if (width > back)
	{
		if (!(result = malloc(width + 1)))
			return (0);
		result[width] = 0;
		for(int i = 0; i < width; i++)
			result[i] = ' ';
		for(int j = ft_strlen(temp) - 1; j >= 0; j--)
			result[--width] = temp[j];
	}
	else
		result = ft_strdup(temp);
	size = write(1, result, ft_strlen(result));
	free(result);
	free(base);
	return (size);
}

int make_result_int(va_list ap, int width, int precision)
{
//	write(1, "why\n", 4);
	int num = va_arg(ap, int);
	if (!num && precision == 0)
		return (zero_check(width));
	char *base = ch_base("0123456789", num);
	int size = ft_strlen(base);
	size = precision > size ? precision : size;
	int back = size;
	char temp[size + 1];
	temp[size] = 0;
	//write(1, base, size);;
	for(int i = 0; i < size; i++)
		temp[i] = '0';
	int j = ft_strlen(base);
	while (j >= 0)
		temp[--size] = base[--j];
	char *result;
	if (width > back)
	{
		if (!(result = malloc(width + 1)))
			return (0);
		result[width] = 0;
		for(int i = 0; i < width; i++)
			result[i] = ' ';
		for(int j = ft_strlen(temp) - 1; j >= 0; j--)
			result[--width] = temp[j];
	}
	else
		result = ft_strdup(temp);
	size = write(1, result, ft_strlen(result));
	free(result);
	free(base);
	return (size);
}

//#include <stdio.h>
int ft_atoi (char *s)
{
	int sign = 1;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	int num = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		//printf("%d\n", num);
	//	printf("%d\n", *s - '0');
		s++;
	}
	//printf("%d\n", num);
	return (num * sign);
}
//#include <stdio.h>
int check_format(va_list ap, char **format)
{
	int width;
	int precision;

	width = 0;
	precision = -1;
	while (**format && (**format != 'd' && **format != 'x' && **format != 's'))
	{
		//write(1, "\n", 1);
		if (**format == '.')
		{
			(*format)++;
			precision = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
		else if (**format >= '0' && **format <= '9')
		{
			width = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
		else
			(*format)++;
	//	printf("%c\n", **format);
		//write(1, *format, 1);
	}
	//printf("w : %d, p : %d\n", width, precision);
	int ret = 0;
	if (**format == 'd')
	{
		ret = make_result_int(ap, width, precision);
		(*format)++;
	}
	else if (**format == 's')
	{
		ret = make_result_str(ap, width, precision);
		(*format)++;
	}
	else if (**format == 'x')
	{
		ret = make_result_base(ap, width, precision);
		(*format)++;
	}
	return (ret);
}

int		ft_printf(char *format, ...)
{
	va_list ap;
	int rt_bytes;

	va_start(ap, format);
	rt_bytes = 0;
	while (*format)
	{
		if (*format != '%')
		{
			rt_bytes += write(1, format, 1);
			format++;
		}
		else
		{
			format++;
			rt_bytes += check_format(ap, &format);
		}
	}
	va_end(ap);
	return (rt_bytes);
}
