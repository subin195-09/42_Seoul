#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void	init_env(char ***env, char *en[])
{
	int		i;
	int		j;

	i = 0;
	while (en[i])
		i++;
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	(*env)[i] = 0;
	j = -1;
	while (++j < i)
		(*env)[j] = strdup(en[j]);
}

char	*find_env(char *key, char **en)
{
	int		i;

	i = -1;
	while (en[++i])
	{
		if (!strncmp(key, en[i], strlen(key)))
			return (en[i]);
	}
	return (0);
}

char	*find_env_val(char *key, char **en)
{
	int		i;
	char	*tmp;
	char	*rt;

	i = -1;
	tmp = find_env(key, en);
	if (!tmp)
		return (0);
	rt = strdup(tmp + strlen(key) + 1);
	return (rt);
}

void	env_changer(char **nd, char **en)
{
	char	cpy_arg[PATH_MAX];
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		cpy_i;
	int		arg_i;
	int		k;
	int		arg_count;

	arg_count = -1;
	while (nd[++arg_count])
	{
		arg_i = -1;
		cpy_i = 0;
		memset(cpy_arg, 0, PATH_MAX);
		while (nd[arg_count][++arg_i])
		{
			if (nd[arg_count][arg_i] == '\'')
			{
				while (nd[arg_count][++arg_i] != '\'')
					cpy_arg[cpy_i++] = nd[arg_count][arg_i];
			}
			if (nd[arg_count][arg_i] == '\"')
			{
				while (nd[arg_count][++arg_i] != '\"')
				{
					if (nd[arg_count][arg_i] == '$')
					{
						memset(key_tmp, 0, PATH_MAX);
						k = 0;
						while (!strchr(" \t\n\r\a\"\'$", nd[arg_count][++arg_i]))
							key_tmp[k++] = nd[arg_count][arg_i];
						key_val = find_env_val(key_tmp, en);
						strcat(cpy_arg, key_val);
						cpy_i += strlen(key_val);
						free(key_val);
					}
					cpy_arg[cpy_i++] = nd[arg_count][arg_i];
				}
			}
			if (nd[arg_count][arg_i] == '$')
			{
				memset(key_tmp, 0, PATH_MAX);
				k = 0;
				while (!strchr(" \t\n\r\a\"\'$", nd[arg_count][++arg_i]))
					key_tmp[k++] = nd[arg_count][arg_i];
				key_val = find_env_val(key_tmp, en);
				strcat(cpy_arg, key_val);
				cpy_i += strlen(key_val);
				free(key_val);
			}
			if (!strchr("\'\"$", nd[arg_count][arg_i]))
				cpy_arg[cpy_i++] = nd[arg_count][arg_i];
		}
		nd[arg_count] = strdup(cpy_arg);
	}
}

int main(int ac, char *av[], char *en[])
{
	int		i;
	char	**env;
	init_env(&env, en);
	char 	*test[] = {"$PATH 123", "\"$HOME\'\"", "why", "\'$HOME\'\"$HOME\'\"", 0};
	i = 0;
	// int a = 0;
	// while (env[a])
	// 	printf("%s\n", env[a++]);
	// printf("%s\n", find_env("PATH", env));
	while (test[i])
	{
		printf("%s\n", test[i]);
		i++;
	}
	env_changer(test, en);
	i = 0;
	while (test[i])
	{
		printf("* : %s\n", test[i]);
		i++;
	}
}