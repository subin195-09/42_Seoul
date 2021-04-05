#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct	s_cir
{
	int		b_width;
	int		b_height;
	char	b_char;
	char	type;
	float	cen_x;
	float	cen_y;
	float	r;
	char	c_char;
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
	int		x;
	int		y;
	float	distance;
	float	f_one = 1.0000000;
	FILE	*file;
	int		read;
	char	*image;
	t_cir	c;

	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &c.b_width, &c.b_height, &c.b_char);
	if (read != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(c.b_width > 0 && c.b_width <= 300 && c.b_height > 0 && c.b_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));
	
	image = (char *)malloc(sizeof(char) * (c.b_width * c.b_height));
	memset(image, c.b_char, c.b_width * c.b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.cen_x, &c.cen_y, &c.r, &c.c_char);
	while (read == 5)
	{
		if (!((c.type == 'c' || c.type == 'C') && c.r > 0))
		{
			free(image);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < c.b_height)
		{
			x = 0;
			while (x < c.b_width)
			{
				distance = sqrtf(powf(c.cen_x - (float)x, 2.) + powf(c.cen_y - (float)y, 2.));
				if (c.type == 'C')
				{
					if (distance <= c.r)
						image[y * c.b_width + x] = c.c_char;
				}
				else if (c.type == 'c')
				{
					if (c.r - distance < f_one)
					{
						if (distance <= c.r)
							image[y * c.b_width + x] = c.c_char;
					}
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.cen_x, &c.cen_y, &c.r, &c.c_char);
	}
	if (read != -1)
	{
		free(image);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < c.b_height)
	{
		write(1, image + y * c.b_width, c.b_width);
		write(1, "\n", 1);
		y++;
	}
	free(image);
	fclose(file);
	return (0);
}	
