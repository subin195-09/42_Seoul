/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 03:00:33 by skim              #+#    #+#             */
/*   Updated: 2020/12/13 03:00:34 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

int press_esc_key(int key, void *param)
{
	if (key == 53 && param)
	{
		write(1, "STOP\n", 5);
		exit(0);
	}
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "창 띄워보기");
	mlx_key_hook(win_ptr, press_esc_key, win_ptr);
	mlx_loop(mlx_ptr);
}
