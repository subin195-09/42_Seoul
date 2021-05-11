#include "microshell.h"

int		exit_fatal(void)
{
	show_error("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void	*exit_fatal_ptr(void)
{
	exit_fatal();
	exit(EXIT_FAILURE);
	return (NULL);
}

int		show_error(char const *str)
{
	if (str)
		write(STDERR, str, strlen(str));
	return (EXIT_FAILURE);
}
