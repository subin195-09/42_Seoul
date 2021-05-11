#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main(void)
{
	char	tmp[1024];
	int				rt;
	DIR* 			t;

	t = NULL;
	getcwd(tmp, 1024);

	// printf("\npwd is %s\n", tmp);
	// t = opendir("test_dirr");

	// if (!t)
	// 	printf("\nt is null!\n");
	// else
	// 	printf("\nI found dir!\n");

	// printf("\n-> : %s\n", strerror(errno));

	// rt = chdir("/Users/skim/Desktop/gun_mandoo_shell/test_skim/allow_test/test_dir");
	rt = chdir("test");
	printf("\nmove to another dir success! re is : %d\n", rt);
	getcwd(tmp, 1024);
	printf("\npwd is %s\n", tmp);

	rt = chdir("../");
	printf("\nmove to another dir success! re is : %d\n", rt);
	getcwd(tmp, 1024);
	printf("\npwd is %s\n", tmp);

	return (0);
}
