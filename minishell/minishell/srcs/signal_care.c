/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_care.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:16:20 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*signal_ctlc(int signo)
{
	if (g_ex.pid == 0)
	{
		write(1, "\ngun_mandoo_shell > ", ft_strlen("\ngun_mandoo_shell > "));
		g_ex.is_signaled = 1;
	}
	else if (g_ex.pid > 0)
		write(1, "\n", 1);
	return (0);
	(void)signo;
}

void	*signal_ctlslash(int signo)
{
	if (g_ex.pid > 0)
		write(2, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	return (0);
	(void)signo;
}
