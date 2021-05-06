#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int	ft_getch(void)
{
	char c;
	int rt;
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // non-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	rt = read(0, &c, sizeof(c));
	if (rt < 0)
		return(-1);
	else
		return ((int)c);
		// if ((int)c[0] == 27)
		// {
		// 	read(0, c, 1);
		// 	if ((int)c[0] == 91)
		// 	{
		// 		read(0, c, 1);
		// 		if ((int)c[0] == 65)
		// 			printf("up key\n");
		// 	}
		// }
}

int main(void)
{
	int c;

	c = 1;
	while (c > 0)
	{
		c = ft_getch();
		if (c == 27)
		{
			c = ft_getch();
			if (c == 91)
			{
				c = ft_getch();
				if (c == 65)
					printf("up\n");
				if (c == 66)
					printf("down\n");
			}
		}
	}

}
