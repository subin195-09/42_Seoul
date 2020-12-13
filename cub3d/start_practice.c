/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 03:00:33 by skim              #+#    #+#             */
/*   Updated: 2020/12/14 00:05:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int press_esc_key(int key, void *a)
{
	int *param = (int *)a;

	printf("현재 a : %d\n", *param);
	if (key == KEY_ESC && a)
	{
		printf("STOP\n");
		exit(0);
	}
	else if (key == KEY_UP && a)
	{
		(*param)++;
		printf("a up : %d\n", *param);
		exit(0);
	}
	else if (key == key_DOWN && a)
	{
		(*param)--;
		printf("a down : %d\n", *param);
		exit(0);
	}
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		a = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "창 띄워보기");

	// 가운데 픽셀 추가
	for (int i = 0; i < 50; i++)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, 225 + i, 225, 0xFFFFFF);
		for (int j = 0; j < 50; j++)
			mlx_pixel_put(mlx_ptr, win_ptr, 225 + i, 225 + j, 0xFFFFFF);
	}

	// 키 이벤트 추가
	//mlx_key_hook(win_ptr, press_esc_key, win_ptr);
	mlx_hook(win_ptr, 2, 0, &press_esc_key, &a);

	// 창에 이미지 로딩하기
	int img_width;
	int img_height;
	img = mlx_xpm_file_to_image(mlx_ptr, "./wall_n.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, 400, 400);

	// 이미지를 만들어서 로딩하기
	t_img	m_img;
	m_img.img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	m_img.data = (int *)mlx_get_data_addr(m_img.img_ptr, &m_img.bpp, &m_img.size_l, &m_img.endian);
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (j % 2)
				m_img.data[i * 100 + j] = 0xFFFFFF;
			else
				m_img.data[i * 100 + j] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, m_img.img_ptr, 0, 0);

	m_img.img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./wall_n.xpm", &m_img.height, &m_img.width);
	m_img.data = (int *)mlx_get_data_addr(m_img.img_ptr, &m_img.bpp, &m_img.size_l, &m_img.endian);
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (j % 2)
				m_img.data[i * 100 + j] = 0xFFFFFF;
			else
				m_img.data[i * 100 + j] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, m_img.img_ptr, 200, 0);

	mlx_loop(mlx_ptr);
}
