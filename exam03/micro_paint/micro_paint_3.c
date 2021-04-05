#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct	s_rect
{
	int		b_width;
	int		b_height;
	char	b_char;

	char	type;
	float	x;
	float	y;
	float	r_width;
	float	r_height;
	char	r_char;
}				t_rect;

int		ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}

void	draw_rect(t_rect r, char **img, int x, int y)
{
	if ((float)x >= r.x && (float)x <= r.x + r.r_width &&\
		(float)y >= r.y && (float)y <= r.y + r.r_height)
			(*img)[y * r.b_width + x] = r.r_char;
}

int 	main(int ac, char *av[])
{
	int		x;
	int		y;
	char	*image;
	FILE	*file;
	int		read;
	float	f_one = 1.0000000;
	t_rect	r;

	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &r.b_width, &r.b_height, &r.b_char);
	if (read != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(r.b_width > 0 && r.b_width <= 300 && r.b_height > 0 && r.b_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));

	image = (char *)malloc(sizeof(char) * (r.b_width * r.b_height));
	memset(image, r.b_char, r.b_width * r.b_height);
	read = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.x, &r.y, &r.r_width, &r.r_height, &r.r_char);
	while (read == 6)
	{
		if (!((r.type == 'r' || r.type == 'R') && r.r_width > 0 && r.r_height > 0))
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
				if (r.type == 'R')
					draw_rect(r, &image, x, y);
				else if (r.type == 'r')
				{
					if (((float)x - r.x < f_one || (r.x + r.r_width) - (float)x < f_one) ||
							((float)y - r.y < f_one || (r.y + r.r_height) - (float)y < f_one))
						draw_rect(r, &image, x, y);
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %f %c\n", &r.type, &r.x, &r.y, &r.r_width, &r.r_height, &r.r_char);
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
