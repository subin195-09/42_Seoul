/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:04:53 by skim              #+#    #+#             */
/*   Updated: 2020/11/18 23:05:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
OPEN_MAX

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;

	if (!s1 || !s2)
		return (0);
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	if (s1_len + s2_len == 0)
		return (strdup(""));
	if (!(result = malloc(s1_len + s2_len + 1)))
		return (0);
	strlcpy(result, s1, s1_len + 1);
	strlcat(result, s2, s1_len + s2_len + 1);
	return (result);
}

int	check_temp(char *str, int size)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (i < size)
	{
		if (str[i] == 0)
			return (0);
		else if (str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

int	gnl_test(int fd, char **line)
{
	static char	*temp;
	char		*temp_one;
	char		*temp_two;
	int			buf_size;
	int			ret;
	int			i;
	int			j;

	buf_size = 3;
	if (!(temp_one = malloc(buf_size)))
		return (-1);
	ret = check_temp(temp_one, buf_size);
	while ((ret = check_temp(temp_two, buf_size)) < 0)
	{
		if (!(temp_two = calloc(buf_size, sizeof(char))))
			return (-1);
		if ((ret = read(fd, temp_two, buf_size)) < 0)
			return (-1);
		temp_one = strdup(*line);
		free(*line);
		(*line) = ft_strjoin(temp_one, temp_two);
		free(temp_one);
		free(temp_two);
	}
	// new line이 있을경우 static 변수에 나머지를 저장
	if (ret == 1)
	{
		while (i < buf_size)
		{
			if ((*line)[i++] == '\n')
				break;
		}
		while (i < buf_size)
		{
			temp[j++] = (*line)[i];
			(*line)[i++] = 0;
		}
	}
	return (ret);
}

int	main(void)
{
	int		fd;
	int		n;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		write(1, "error\n", 6);
	n = gnl_test(fd, &line);
	if (n == 0)
	{
		write(1, "EOF\n", 4);
		write(1, line, strlen(line));
	}
	else if (n == 1)
	{
		write(1, "new line\n", 9);
		write(1, line, strlen(line));
	}
	else
		write(1, "error\n", 6);
}
