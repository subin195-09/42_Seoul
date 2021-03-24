/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:20:48 by skim              #+#    #+#             */
/*   Updated: 2021/03/24 15:56:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "test_bonus.h"

void	ft_list_push_front(t_list **list, void *data);
int		ft_list_size(t_list *begin_list);
char	*ft_strdup(char *src);

int main(void)
{
	t_list *head;
	t_list *temp;
	head = 0;
	ft_list_push_front(&head, ft_strdup("123"));
	ft_list_push_front(&head, ft_strdup("456"));
	ft_list_push_front(&head, ft_strdup("789"));
	temp = head;
	while (temp)
	{
		printf("[%s]", (char *)temp->data);
		if (temp->next)
			printf(" -> ");
		temp = temp->next;
	}
	printf("\nlist size : %d\n", ft_list_size(head));
}
