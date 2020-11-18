/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:37:37 by skim              #+#    #+#             */
/*   Updated: 2020/11/18 23:39:36 by skim             ###   ########.fr       */
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

char	*check_new_line(char *temp_one)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (i < BUF_SIZE && temp_one[i] != '\n')
		i++;
	if (!(result = malloc(i)))
		return (0);
	j = -1;
	while (++j < i)
		result[j] = temp_one[j];
	return (result);
}

int		restore_temp(char **temp, char *temp_one)
{
	int		i;
	int		j;

	i = 0;
	while (i < BUF_SIZE && temp_one[i] != '\n')
		i++;
	free(*temp);
	*temp = 0;
	if (i < BUF_SIZE)
	{
		if (!(*temp = malloc(BUF_SIZE - i)))
			return (-1);
		j = 0;
		while (++i < BUF_SIZE)
			(*temp)[j++] = temp_one[i];
	}
	return (1);
}

int		gnl_test3(int fd, char **line)
{
	static char	*temp[OPEN_MAX];
	static int	test;
	char		*temp_one;
	char		*temp_two;
	int			ret;

	if (!(temp_one = malloc(BUF_SIZE * sizeof(char))))
		return (-1);
	if ((ret = read(fd, temp_one, BUF_SIZE)) <= 0)
		return (ret);
	if (!(temp_two = check_new_line(temp_one)))
		return (-1);
	*line = temp == 0 ? strdup(temp_two) : ft_strjoin(temp, temp_two);
	ret = restore_temp(&temp, temp_one);
	printf("temp : %s\n", temp);
	return (ret);
}
