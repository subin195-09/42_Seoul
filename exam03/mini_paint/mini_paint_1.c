#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct	s_cir
{
	int			b_width;
	int			b_height;
	char		b_char;

	char		type;
	float		x;
	float		y;
	float		ra;
	char		r_char;
}				t_cir;

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}


int		main(int ac, char *av[])
{
	FILE	*file;
	int		read;
	int		x;
	int		y;
	char	*image;
	t_cir	c;

	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &c.b_width, &c.b_height, &c.b_char);
	if (read != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!((c.b_width > 0 && c.b_width <= 300) && (c.b_height > 0 && c.b_height <= 300)))
		return (ft_putstr("Error: Operation file corrupted\n"));

	image = (char *)malloc(sizeof(char) * (c.b_width * c.b_height));
	memset(image, c.b_char, c.b_width * c.b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.ra, &c.r_char);
	while (read == 5)
	{
		if (!((c.type == 'c' || c.type == 'C') && c.ra > 0))
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
				float distance = sqrtf(powf(x - c.x, 2.) + powf(y - c.y, 2.));
				if (distance <= c.ra)
				{
					if (c.type == 'c')
					{
						if (c.ra - distance < 1.0000000)
							image[y * c.b_width + x] = c.r_char;
					}
					else if (c.type == 'C')
						image[y * c.b_width + x] = c.r_char;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.x, &c.y, &c.ra, &c.r_char);
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
	return (0);
}
