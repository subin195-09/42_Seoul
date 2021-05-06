#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	 redirect_count(char *arg)
{
	int	qq_f;
	int	q_f;
	int	i;
	int	count;

	i = -1;
	qq_f = 1;
	q_f = 1;
	count = 1;
	while (arg[++i])
	{
		if (arg[i] == '\'')
			q_f *= -1;
		else if (arg[i] == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			if (arg[i + 1] == '>')
				i++;
			if (arg[i + 1])
				count++;
			count++;
		}
	}
	return (count);
}

void	sep_redirect(char ***rt, int *size, char *arg)
{
	char	temp[1024];
	int		qq_f;
	int		q_f;
	int		j;

	j = 0;
	qq_f = 1;
	q_f = 1;
	memset(temp, 0, 1024);
	while (*arg)
	{
		if (*arg == '\'')
			q_f *= -1;
		else if (*arg == '\"')
			qq_f *= -1;
		if (q_f > 0 && qq_f > 0 && (*arg == '>' || *arg == '<'))
		{
			if (strlen(temp) > 0)
			{
				(*rt)[*size] = strdup(temp);
				memset(temp, 0, 1024);
				j = 0;
				(*size)++;
			}
			temp[j++] = *arg;
			if (*(arg + 1) == '>')
				temp[j++] = *(arg++);
			(*rt)[*size] = strdup(temp);
			memset(temp, 0, 1024);
			j = 0;
			(*size)++;
		}
		else
			temp[j++] = *arg;
		arg++;
	}
	if (strlen(temp) > 0)
	{
		(*rt)[*size] = strdup(temp);
		(*size)++;
	}
}

char	**split_redirect(char **b_arg)
{
	char	**rt;
	int		size;
	int		i;

	size = 0;
	i = -1;
	while (b_arg[++i])
		size += redirect_count(b_arg[i]);
	rt = (char **)malloc(sizeof(char *) * (size + 1));
	rt[size] = 0;
	i = -1;
	size = 0;
	while (b_arg[++i])
	{
		if (redirect_count(b_arg[i]) == 1)
			rt[size++] = strdup(b_arg[i]);
		else
			sep_redirect(&rt, &size, b_arg[i]);
	}
	return (rt);
}

int main(void)
{
	char **test;
	char **rt;
	int size = 3;

	test = malloc(sizeof(char *) * size);
	test[0] = strdup("ec>>ho");
	test[1] = strdup(">123>");
	test[size - 1] = 0;
	int i = 0;
	while (test[i])
		printf("%s\n", test[i++]);
	rt = split_redirect(test);
	printf("\n\n");
	i = 0;
	while (rt[i])
		printf("%s\n", rt[i++]);
}
