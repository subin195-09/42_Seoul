/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:37:37 by skim              #+#    #+#             */
/*   Updated: 2020/11/19 19:18:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#define BUF_SIZE 5

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

char	*ft_restore(char **store, int ret)
{
	char	*result;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while ((*store)[i] && ((*store)[i] != '\n'))
		i++;
	if (!(result = malloc(i + 1)))
		return (0);
	if (!(temp = malloc(strlen((*store) - i))))
		return (0);
	result[i] = 0;
	while(++j < i)
		result[j] = (*store)[j];
	i = 0;
	while ((*store)[++j])
		temp[i++] = (*store)[j];
	free(*store);
	(*store) = strdup(temp);
	free(temp);
	return (result);
}

int		gnl_test3(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		*temp_one;
	char		*temp_two;
	int			flag;
	int			ret;

	flag = 0;
	while (!flag || (!(strchr(store[fd], '\n')) && ret > 0))
	{
		flag = 1;
		if (!(temp_two = malloc(BUF_SIZE)))
			return (-1);
		ret = read(fd, temp_two, BUF_SIZE);
		temp_one = store[fd] ? strdup(store[fd]) : strdup("");
		free(store[fd]);
		store[fd] = flag == 0 ? ft_strjoin(temp_two, temp_one) : ft_strjoin(temp_one, temp_two);
		free(temp_one);
		free(temp_two);
		flag = 1;
	}
	*line = ft_restore(&store[fd], ret);
	return (ret > 0 ? 1 : 0);
}

int		main(void)
{
	int		fd;
	int		n;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		write(1, "error\n", 6);
	// gnl_test3(fd, &line);
	// printf("%s\n", line);
	while ((n = gnl_test3(fd, &line)) > 0)
	{
		printf("result : %s\n", line);
		printf("return : %d\n", n);
	}
	printf("return : %d\n", n);
}
