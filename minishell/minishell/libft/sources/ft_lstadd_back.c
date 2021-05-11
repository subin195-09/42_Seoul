/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 08:55:57 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/06 09:16:42 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mover;

	if (!*lst)
		*lst = new;
	mover = *lst;
	while (mover->next != NULL)
		mover = mover->next;
	mover->next = new;
	new->next = NULL;
}
