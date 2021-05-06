/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_care.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:48:17 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*signal_ctlc(int signo)
{
	if (g_ex.pid == 0)
		write(1, "\b\b\ngun_mandoo_shell > ", \
		ft_strlen("\b\b\ngun_mandoo_shell > "));
	else if (g_ex.pid > 0)
		printf("\n");
	return (0);
	(void)signo;
}

void	*signal_ctlslash(int signo)
{
	if (g_ex.pid > 0)
		write(1, "Quit: 3\n", ft_strlen("Quit: 3\n"));
	return (0);
	(void)signo;
}
