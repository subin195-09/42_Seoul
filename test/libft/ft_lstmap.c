/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:10:06 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 01:15:21 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp_lst;

	if (!lst || !f || !del)
		return (0);
	head = 0;
	while(lst)
	{
		if (!(temp_lst = ft_lstnew(f(lst))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, temp_lst);
		lst = lst->next;
	}
	return (head);
}
