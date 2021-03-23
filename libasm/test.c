/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/23 12:14:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

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

	printf("\n\n*ft_strcpy test\n");
	char d[10];
	printf("ft_strcpy : %s\n", ft_strcpy(d, ""));
	printf("%s\n", d);
	printf("ft_strcpy : %s\n", ft_strcpy(d, "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789"));
	printf("%s\n", d);

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
	printf("\nwrite return : %zd\n", ft_write(1, "hello", -9));

	int fd = open("test.txt", O_RDONLY);
	char buf[10];
	printf("\nread return : %zd\n", ft_read(fd, buf, 3));
	printf("read buf : %s\n", buf);

	char *mal = ft_strdup("42seoul\n");
	printf("%s", mal);
	return (0);
}
