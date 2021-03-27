#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_rect
{
	int		b_width;
	int		b_height;
	char	b_char;

	char	type;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	c_char;
}				t_rect;

int		ft_putstr(char *s)
{
	int		i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}

void	draw_rect(t_rect r, char **image, int x,  int y)
{
	if (r.start_x <= (float)x  && (float)x <= (r.start_x + r.width) && r.start_y <= (float)y && (float)y <= (r.start_y + r.height))
		(*image)[y * r.b_width + x] = r.c_char;
}

int		main(int ac, char *av[])
{
	FILE	*file;
	t_rect	r;
	char	*image;
	int		read;

	// error 처리
	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	if ((fscanf(file, "%d %d %c\n", &r.b_width, &r.b_height, &r.b_char)) != 3)
		return (ft_putstr("Error: operation file1\n"));
	if (!(0 < r.b_width && r.b_width <= 300 && 0 < r.b_height && r.b_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));

	image = (char *)malloc(sizeof(char) * (r.b_width * r.b_height));
	memset(image, r.b_char, r.b_width * r.b_height);
	read = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.start_x, &r.start_y, &r.width, &r.height, &r.c_char);

	int y = 0;
	int x = 0;
	float	f_one = 1.0000000;
	while (read == 6)
	{
		if (!(r.width > 0 && r.height > 0) || !(r.type == 'r' || r.type == 'R'))
		{
			free(image);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < r.b_height)
		{
			x = 0;
			while (x < r.b_width)
			{
				if (r.type == 'r')
				{
					if (x - r.start_x < f_one || (r.start_x + r.width) - x < f_one \
					|| y - r.start_y < f_one || (r.start_y + r.height) - y < f_one)
						draw_rect(r, &image, x, y);
				}
				else if (r.type == 'R')
					draw_rect(r, &image, x, y);
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.start_x, &r.start_y, &r.width, &r.height, &r.c_char);
	}

	if (read != -1)
	{
		free(image);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}

	y = 0;
	while (y < r.b_height)
	{
			write(1, image + y * r.b_width, r.b_width);
			write(1, "\n", 1);
			y++;
	}
	free(image);
	fclose(file);
	return (0);
}
