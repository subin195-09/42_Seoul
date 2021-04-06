#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct	s_cir
{
	int		b_width;
	int		b_height;
	char	b_char;
	char	type;
	float	center_x;
	float	center_y;
	float	rad;
	char	cir;
}				t_cir;

int		ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (1);
}

int		main(int ac, char *av[])
{
	t_cir	c;
	char	*img;
	int		x;
	int		y;
	float	distance;
	float	f_one = 1.0000000;
	FILE	*file;
	int		read;

	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &c.b_width, &c.b_height, &c.b_char);
	if (read != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(c.b_width > 0 && c.b_width <= 300 && c.b_height > 0 && c.b_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(img = (char *)malloc(sizeof(char) * (c.b_width * c.b_height))))
		return (ft_putstr("Error: Operation file corrupted\n"));
	memset(img, c.b_char, c.b_width * c.b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.center_x, &c.center_y, &c.rad, &c.cir);
	while (read == 5)
	{
		if (!((c.type == 'c' || c.type == 'C') && c.rad > 0))
		{
			free(img);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < c.b_height)
		{
			x = 0;
			while (x < c.b_width)
			{
				distance = sqrtf(powf(c.center_x - (float)x, 2.) + powf(c.center_y - (float)y, 2.));
				if (c.type == 'C')
				{
					if (distance <= c.rad)
						img[y * c.b_width + x] = c.cir;
				}
				else if (c.type == 'c')
				{
					if (c.rad - distance < f_one)
						if (distance <= c.rad)
							img[y * c.b_width + x] = c.cir;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.center_x, &c.center_y, &c.rad, &c.cir);
	}
	if (read != -1)
	{
		free(img);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < c.b_height)
	{
		write(1, img + y * c.b_width, c.b_width);
		write(1, "\n", 1);
		y++;
	}
	free(img);
	fclose(file);
	return (0);
}
