#include "test.h"

char	*read_line(void)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	return (line);
}

int		run_cmd(char **coms, char **en, char *av)
{
	char	**run_com;
	int		rt;
	int		i;
	int		j;

	i = -1;
	rt = 1;
	while (coms[++i])
	{
		run_com = make_tok(coms[i], " ");
		// 트리구조의 헤드를 넘겨줄 예정
		read_run(coms);
		rt = run(run_com, en, av);
		free(coms[i]);
		j = -1;
		while (run_com[++j])
			free(run_com[j]);
		if (run_com)
			free(run_com);
	}
	return (rt);
}

t_nd	*new_nd(char *name)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
	if (!tmp_nd->args)
		return (NULL);
	tmp_nd->args[0] = ft_strdup(name);
	tmp_nd->args[1] = 0;
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->prev = 0;
	tmp_nd->type = -1;
	tmp_nd->pos->head = 0;
	tmp_nd->pos->tail = 0;
	tmp_nd->re->rdrt_yn = 0;
	tmp_nd->re->rdrt_fd = 0;
	return (tmp_nd);
}

t_nd	*parse(char *str, char *charset)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	i = -1;
	tmp = make_tok(str, charset);
	// 빅 토큰라인들이 들어있는 tmp
	mother = new_nd(str);
	mother->pos->head = mother;
	mother->pos->tail = mother;
	while (tmp[++i])
	{
		if (i == 0)
		{
			mother->child = new_nd(tmp[i]);
			mother->child->prev = mother;
			tmp_nd = mother->child;
		}
		else
		{
			tmp_nd->sible = new_nd(tmp[i]);
			tmp_nd->sible->prev = tmp_nd;
			tmp_nd = tmp_nd->sible;
		}
	}


	tmp_nd = mother;
	printf("{ %s }", tmp_nd->args[0]);
	while(tmp_nd->child)
	{
		printf("\n|\n -> { %s }",tmp_nd->child->val);
		tmp_nd = tmp_nd->child;
		while(tmp_nd->sible)
		{
			printf(" -> { %s }",tmp_nd->sible->val);
			if(tmp_nd->sible)
				tmp_nd = tmp_nd->sible;
		}
	}
	printf("\n");

	return	mother;
}

char	*get_ch()
{
	char	c;
	char	*tmp;
	char	*tmp2;

	tmp	= (char *)malloc(sizeof(char) * 1);
	tmp[0] = 0;
	while (read(0, &c, sizeof(c)) > 0)
	{
		if(tmp[0] == 0)
			tmp[0] = c;
		else
			tmp2 = ft_strjoin(tmp, c); 
	}
	return (tmp2);
}

int		start_shell(char **en, char *av)
{
	int		status;
	char	*line;
	char	**coms;

	status = 1;
	//start_write();
	while (status)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = get_ch;
		coms = parse(line, ";");
		status = run_cmd(coms, en, av);
	}
	return (0);
}
