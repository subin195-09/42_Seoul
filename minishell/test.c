#include <stdio.h>
#include <libft.h>
#include <get_next_line.h>

char	*read_line(void)
{
	char *line;

	line = 0;
	get_next_line(0, &line);
	return (line);
}

int main(int ac, char *av[], char *en[])
{
	char *line;
	int status = 1;

	while (status)
	{
		line = read_line();
		printf("%s\n", line);
		if (ft_strncmp("exit", line, 5) == 0)
			status = 0;
	}
	return (0);
}
