/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/23 12:30:34 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *d);
char	*ft_strcpy(char *d, char *s);
int		ft_strcmp(char *s1, char *s2);
ssize_t	ft_write(int fd, char *buf, int size);
ssize_t	ft_read(int fd, char *buf, int size);
char	*ft_strdup(char *s);

int main(void)
{
	printf("*ft_strlen test\n");
	printf("ft_strlen : %lu\n", ft_strlen(""));
	printf("ft_strlen : %lu\n", ft_strlen("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));

	// printf("\n\n*ft_strcpy test\n");
	// char d[10];
	// printf("ft_strcpy : %s\n", ft_strcpy(d, ""));
	// printf("%s\n", d);
	// printf("ft_strcpy : %s\n", ft_strcpy(d, "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
	// printf("%s\n", d);

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
	printf("11, 1 : %d\n", ft_strcmp("1", "11"));
	printf("11, 1 : %d\n", strcmp("1", "11"));

	printf("\n\n*ft_write test\n");
	int fd = open("test.txt", O_WRONLY);
	printf("\nwrite return : %zd\n", ft_write(1, "hello", 5));
	printf("\nwrite return : %zd\n", ft_write(-1, "hello", 5));
	printf("\nwrite return : %zd\n", ft_write(fd, "hello", 5));
	close(fd);

	printf("\n\n*ft_read test\n");
	fd = open("test.txt", O_RDONLY);
	char buf[10];
	printf("read return : %zd\n", ft_read(1, buf, 5));
	printf("read buf : %s\n\n", buf);
	printf("read return : %zd\n", ft_read(fd, buf, 5));
	printf("read buf : %s\n\n", buf);
	printf("read return : %zd\n", ft_read(-1, buf, 5));

	printf("\n\n*ft_malloc test\n");
	char *mal = ft_strdup("");
	printf("%s<\n", mal);
	free(mal);
	mal = ft_strdup("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	printf("%s\n", mal);
	free(mal);

	return (0);
}
