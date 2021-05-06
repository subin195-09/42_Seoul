#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <curses.h>
#include <term.h>

int		main(void)
{
	char	buf[PATH_MAX];
	// char	buf2[30];
	// char	*ap = buf2;
	// char	*clearstr, *gotostr, *standstr, *stendstr;

	// ㅇㅏ직 실행안됨 
	tgetent(buf, getenv("TERM"));
}
