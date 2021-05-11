#include <stdio.h>


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char str1;
	unsigned char str2;

	while (n > 0)
	{
		str1 = *(unsigned char *)s1++;
		str2 = *(unsigned char *)s2++;
		if (str1 != str2)
			return (str1 - str2);
		if (str1 == '\0')
			return (0);
		n--;
	}
	return (0);
}


size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}



// void	init_env(char ***env, char *en[])
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (en[i])
// 		i++;
// 	if (!(*env = (char **)malloc(sizeof(char *) * (i + 1))))
// 		return ;
// 	(*env)[i] = 0;
// 	j = -1;
// 	while (++j < i)
// 		(*env)[j] = ft_strdup(en[j]);
// }

int		main(int ac, char *av[], char *en[])
{
	char	**env;
	// char	rt;
	char	tmp1[]= "abcde";
	char	tmp2[]= "abcdefg";
	int		rt;
	// struct termios term;

	// tcgetattr(STDIN_FILENO, &term);
	// term.c_lflag &= ~ICANON;    // non-canonical input 설정
	// term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	// term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	// term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
	// tcsetattr(STDIN_FILENO, TCSANOW, &term);

	// init_env(&env, en);

	rt = ft_strncmp(tmp1, tmp2, ft_strlen(tmp1));
	printf("[%s] [%s]\n\n",tmp1, tmp2);
	printf("[%d]",rt);
	return (0);
// 	rt = start_shell(env, av[0]);
}