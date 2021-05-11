#include "test.h"

int		cmd_pwd(t_nd run_cum, char **en, char *av)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, PATH_MAX);
	write(1, pwd, strlen(pwd));
	return (1);
}

// int		main()
// {
// 	char	buf[PATH_MAX];

// 	 getcwd(buf, PATH_MAX);
// 	printf("%s\n", buf);
// }
