/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:28:44 by skim              #+#    #+#             */
/*   Updated: 2021/03/24 17:24:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_BONUS_H
# define FT_TEST_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void				ft_list_push_front(t_list **list, void *data);
int					ft_list_size(t_list *begin_list);
char				*ft_strdup(char *src);

#endif
