#include "get_next_line.h"

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

char	*ft_strndup(char *s, int n)
{
	char	*result;
	int		i = 0;

	if (!(result = malloc(n + 1)))
		return (0);
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		size_one;
	int		size_two;
	int		i = 0;

	size_one = ft_strlen(s1);
	size_two = ft_strlen(s2);
	if (!(result = malloc(size_one + size_two + 1)))
		return (0);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}

int		ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int		ft_restore(char **store, char **line)
{
	char	*temp;
	int		i = 0;

	if (ft_strchr(*store, '\n'))
	{
		while ((*store)[i] != '\n')
			i++;
		*line = ft_strndup((*store), i);
		temp = ft_strdup((*store) + i + 1);
		free((*store));
		*store = temp;
		free(temp);
		temp = 0;
		return (1);
	}
	else
	{
		*line = ft_strdup(*store);
		free(*store);
		*store = 0;
		return (0);
	}
}	

int		get_next_line(char **line)
{
	static char	*store;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (BUFFER_SIZE <= 0 || !line)
		return (-1);
	while ((ret = read(0, buf, BUFFER_SIZE)) >= 0)
	{
		buf[BUFFER_SIZE] = 0;
		if (!(store = !store ? ft_strdup(buf) : ft_strjoin(store, buf)))
			return (-1);
		if (ft_strchr(store, '\n') || ret <= 0)
			break;
	}
	if (ret < 0)
		return (-1);
	ret = ft_restore(&store, line);
	return (ret);
}

