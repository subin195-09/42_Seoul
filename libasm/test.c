/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/03/23 10:52:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int		ft_strlen(char *d);
char	*ft_strcpy(char *d, char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, char *buf, int size);
int		ft_read(int fd, char *buf, int size);
char	*ft_strdup(char *s);

int main(void)
{
	char d[10];
	printf("ft_strcpy : %s\n", ft_strcpy(d, "hello"));
	printf("%s\n", d);

	printf("ft_strlen : %d\n", ft_strlen(d));
	printf("strlen : %lu\n", strlen(d));

	printf("11, 1 : %d\n", ft_strcmp("11", "1"));
	printf("11, 1 : %d\n", strcmp("11", "1"));
	printf("11, 11 : %d\n", ft_strcmp("11", "11"));
	printf("11, 11 : %d\n", strcmp("11", "11"));
	printf("1, 11 : %d\n", ft_strcmp("1", "11"));
	printf("1, 11 : %d\n", strcmp("1", "11"));

	printf("\nwrite return : %d\n", ft_write(1, "hello", -9));

	int fd = open("test.txt", O_RDONLY);
	char buf[10];
	printf("\nread return : %d\n", ft_read(fd, buf, 3));
	printf("read buf : %s\n", buf);

	char *mal = ft_strdup("42seoul\n");
	printf("%s", mal);
	return (0);
}
