/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/24 17:27:37 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strlen_strcpy(void)
{
	char d[200];

	printf("*ft_strlen test\n");
	printf("ft_strlen : %lu\n", ft_strlen(""));
	printf("ft_strlen : %lu\n", \
	ft_strlen("01234567890123456789012345678901234\
56789012345678901234567890123456789012345678901\
2345678901234567890123456789"));
	printf("\n\n*ft_strcpy test\n");
	printf("ft_strcpy : %s\n", ft_strcpy(d, ""));
	printf("%s\n", d);
	printf("ft_strcpy : %s\n", ft_strcpy(d, \
	"0123456789012345678901234567890123456789\
012345678901234567890123456789012345678901\
2345678901234567890123456789"));
	printf("%s\n", d);
}

void	test_strcmp(void)
{
	printf("\n\n*ft_strcmp test\n");
	printf(" , : %d\n", ft_strcmp("", ""));
	printf(" , : %d\n", strcmp("", ""));
	printf(" , 1 : %d\n", ft_strcmp("", "1"));
	printf(" , 1 : %d\n", strcmp("", "1"));
	printf("1, : %d\n", ft_strcmp("1", ""));
	printf("1, : %d\n", strcmp("1", ""));
	printf("11, 11 : %d\n", ft_strcmp("11", "11"));
	printf("11, 11 : %d\n", strcmp("11", "11"));
	printf("1, 11 : %d\n", ft_strcmp("1", "11"));
	printf("1, 11 : %d\n", strcmp("1", "11"));
	printf("11, 1 : %d\n", ft_strcmp("11", "1"));
	printf("11, 1 : %d\n", strcmp("11", "1"));
}

void	test_write_read(void)
{
	int		fd;
	char	buf[10];

	printf("\n\n*ft_write test\n");
	fd = open("./test/test.txt", O_WRONLY);
	printf("\nwrite return : %zd\n", ft_write(1, "hello", 5));
	printf("\nwrite return : %zd\n", ft_write(-1, "hello", 5));
	printf("\nwrite return : %zd\n", ft_write(fd, "hello", 5));
	close(fd);
	printf("\n\n*ft_read test\n");
	fd = open("./test/test.txt", O_RDONLY);
	printf("read return : %zd\n", ft_read(1, buf, 5));
	printf("read buf : %s\n\n", buf);
	printf("read return : %zd\n", ft_read(fd, buf, 5));
	printf("read buf : %s\n\n", buf);
	printf("read return : %zd\n", ft_read(-1, buf, 5));
}

void	test_strdup(void)
{
	char *mal;

	printf("\n\n*ft_malloc test\n");
	mal = ft_strdup("");
	printf("%s<\n", mal);
	free(mal);
	mal = ft_strdup("0123456789012345678901234567\
8901234567890123456789012345678901234567890123\
456789012345678901234567890123456789");
	printf("%s\n", mal);
	free(mal);
}

int		main(void)
{
	test_strlen_strcpy();
	test_strcmp();
	test_write_read();
	test_strdup();
	return (0);
}
