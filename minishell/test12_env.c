/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:04:18 by skim              #+#    #+#             */
/*   Updated: 2021/04/08 21:05:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		cmd_env(char **run_com, char **en, char *av)
{
	int		i;

	i = -1;
	while (en[++i])
		printf("%s\n", en[i]);
	return (1);
}
