#include "get_next_line_3.h"

int ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *ret;
	int i = ft_strlen(s);

	if (!(ret = malloc(i + 1)))
		return (0);
	ret[i] = 0;
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	return (ret);
}

char *ft_strndup(char *s, int n)
{
	char *ret;

	if (!(ret = malloc(n + 1)))
		return (0);
	int i;
	for(i = 0; i < n; i++)
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

int ft_strchr(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	char *ret;

	if (!(ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

int	ft_restore(char **store, char **line)
{
	if (ft_strchr(*store, '\n'))
	{
		int i = 0;
		while ((*store)[i] != '\n')
			i++;
		*line = ft_strndup(*store, i);
		char *temp = ft_strdup(*store + i + 1);
		free(*store);
		*store = ft_strdup(temp);
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

int get_next_line(char **line)
{
	static char *store[1];
	char *temp;
	char buf[2];
	int ret;

	if (!line)
		return (-1);
	while ((ret = read(1, buf, 1)) >= 0)
	{
		buf[1] = 0;
		temp = !store[0] ? ft_strdup(buf) : ft_strjoin(store[0], buf);
		if (store[0])
			free(store[0]);
		store[0] = ft_strdup(temp);
		free(temp);
		temp = 0;
		if (ret == 0 || ft_strchr(store[0], '\n'))
			break;
	}
	if (ret == -1)
		return (-1);
	ret = ft_restore(&store[0], line);
	return (ret);
}

