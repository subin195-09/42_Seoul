/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:41 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:04:20 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redirect_type(t_nd *nd, int arg_count)
{
	if (nd->args[arg_count][1] == '>')
	{
		nd->re.rdrt_type = RE_TYPE_OOUT;
		return (RE_TYPE_OOUT);
	}
	else if (nd->args[arg_count][0] == '>')
	{
		nd->re.rdrt_type = RE_TYPE_OUT;
		return (RE_TYPE_OUT);
	}
	else if (nd->args[arg_count][0] == '<')
	{
		nd->re.rdrt_in_type = RE_TYPE_IN;
		return (RE_TYPE_IN);
	}
	return (-1);
}

int	get_redirect_fd(int type, t_nd *nd)
{
	if (type == RE_TYPE_OUT)
		nd->re.rdrt_fd = open(nd->re.rdrt_name, O_RDWR | O_CREAT |\
		O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
	else if (type == RE_TYPE_OOUT)
		nd->re.rdrt_fd = open(nd->re.rdrt_name, O_RDWR | O_CREAT |\
		O_APPEND, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
	else if (type == RE_TYPE_IN)
		nd->re.rdrt_in_fd = open(nd->re.rdrt_in_name, O_RDONLY, S_IRUSR |\
		S_IWUSR | S_IROTH | S_IRGRP);
	if (nd->re.rdrt_fd < 0)
	{
		close(nd->re.rdrt_fd);
		return (EXIT_FAILURE);
	}
	else if (nd->re.rdrt_in_fd < 0)
	{
		ft_putendl_fd("No such file or directory", 2);
		close(nd->re.rdrt_in_fd);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	get_redirect_info(t_nd *nd, int arg_count)
{
	int	type;

	type = get_redirect_type(nd, arg_count);
	if (type != RE_TYPE_IN && nd->re.rdrt_fd > 0)
	{
		close(nd->re.rdrt_fd);
		free(nd->re.rdrt_name);
	}
	if (type == RE_TYPE_IN && nd->re.rdrt_in_fd > 0)
	{
		close(nd->re.rdrt_in_fd);
		free(nd->re.rdrt_in_name);
	}
	free(nd->args[arg_count]);
	nd->args[arg_count] = 0;
	if (type == RE_TYPE_IN)
		nd->re.rdrt_in_name = ft_strdup(nd->args[arg_count + 1]);
	else
		nd->re.rdrt_name = ft_strdup(nd->args[arg_count + 1]);
	free(nd->args[arg_count + 1]);
	nd->args[arg_count + 1] = 0;
	if (get_redirect_fd(type, nd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
