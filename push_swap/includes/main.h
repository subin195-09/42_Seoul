/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:27:33 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 17:36:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define STDERR 2
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}				t_stack;

typedef struct	s_info
{
	int			count;
	int			size;
	int			max;
	int			min;
}				t_info;

#endif
