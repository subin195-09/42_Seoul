/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 18:10:06 by skim              #+#    #+#             */
/*   Updated: 2020/10/02 15:54:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp_curr;
	t_list	*temp_next;

	if (!lst || !f || !del)
		return (0);
	if (!(head = ft_lstnew(f(lst->content))))
		return (0);
	temp_curr = head;
	temp_next = lst->next;
	while (temp_next)
	{
		if (!(temp_curr->next = ft_lstnew(f(temp_next->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		temp_curr = temp_curr->next;
		temp_next = temp_next->next;
	}
	return (head);
}
