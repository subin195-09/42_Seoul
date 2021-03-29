#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_cir
{
	int		b_width;
	int		b_height;
	char	b_char;
	
	char	type;
	float	center_x;
	float	center_y;
	float	radius;
	char	circle_c;
}				t_cir;

int		ft_putstr(char *s)
{
	int	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}

void	draw_circle(t_cir c, char **image, int x, int y, float distance)
{
	if (distance <= c.radius)
		(*image)[y * c.b_width + x] = c.circle_c;
}

int		main(int ac, char *av[])
{
	FILE	*file;
	int		read;
	char	*image;
	int		x;
	int		y;
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
	read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.center_x, &c.center_y, &c.radius, &c.circle_c);
	while (read == 5)
	{
		if (!((c.type == 'c' || c.type == 'C') && (c.radius > 0)))
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
				float distance = sqrtf(powf((float)x - c.center_x, 2.) + powf((float)y - c.center_y, 2.));
				if (c.type == 'C')
					draw_circle(c, &image, x, y, distance);
				else if (c.type == 'c')
				{
					if (c.radius - distance < 1.0000000)
						draw_circle(c, &image, x, y, distance);
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &c.type, &c.center_x, &c.center_y, &c.radius, &c.circle_c);
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
