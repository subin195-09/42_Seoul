#include "get_next_line_2.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(char c, char *s)
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

char *ft_strdup(char *s)
{
	int size = ft_strlen(s);
	char *ret;
	int i;

	if (!(ret = malloc(size + 1)))
		return (0);
	for(i = 0; i < size; i++)
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

char *ft_strjoin(char *s1, char *s2)
{
	int size = ft_strlen(s1) + ft_strlen(s2);
	int i = 0;
	char *ret;

	if (!(ret = malloc(size + 1)))
		return (0);
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

char *ft_strndup(char *s, int n)
{
	char *ret;

	if (!(ret = malloc(n + 1)))
		return (0);
	ret[n] = 0;
	for (int i = 0; i < n; i++)
		ret[i] = s[i];
	return (ret);
}

int	ft_restore(char **line, char **store)
{
	if (ft_strchr('\n', *store))
	{
		int i = 0;
		while ((*store)[i] != '\n')
			i++;
		*line  = ft_strndup(*store, i);
		char *temp = ft_strdup((*store) + i + 1);
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


int	get_next_line(char **line)
{	
	static char *store[1];
	char buf[2];
	int	ret;
	if (!line)
		return (-1);
	while ((ret = read(0, buf, 1)) >= 0)
	{
		//write(1, "why?\n", 5);
		buf[1] = 0;
		if (!(store[0] = !store[0] ? ft_strdup(buf) : ft_strjoin(store[0], buf)))
			return (-1);
		if (ft_strchr('\n', store[0]))
			break;
		if (ret == 0)
			break;
	}
	if (ret == -1)
		return (-1);
	ret = ft_restore(line, &store[0]);
	return (ret);
}
