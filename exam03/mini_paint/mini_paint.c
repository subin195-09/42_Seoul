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
	float	cen_x;
	float	cen_y;
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
	t_cir	r;
	int		x;
	int		y;
	char	*img;
	float	f_one = 1.0000000;;
	int		read;
	FILE	*file;

	if (ac != 2)
		return (ft_putstr("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (ft_putstr("Error: Operation file corrupted\n"));
	read = fscanf(file, "%d %d %c\n", &r.b_width, &r.b_height, &r.b_char);
	if (read != 3)
		return (ft_putstr("Error: Operation file corrupted\n"));
	if (!(r.b_width > 0 && r.b_width <= 300 && r.b_height > 0 && r.b_height <= 300))
		return (ft_putstr("Error: Operation file corrupted\n"));
	
	img = (char *)malloc(sizeof(char) * (r.b_width * r.b_height));
	memset(img, r.b_char, r.b_width * r.b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &r.type, &r.cen_x, &r.cen_y, &r.rad, &r.cir);
	while (read == 5)
	{
		if (!((r.type == 'c' || r.type == 'C') && r.rad > 0))
		{
			free(img);
			return (ft_putstr("Error: Operation file corrupted\n"));
		}
		y = 0;
		while (y < r.b_height)
		{
			x = 0;
			while (x < r.b_width)
			{
				float distance = sqrtf(powf(r.cen_x - (float)x, 2.) + powf(r.cen_y - (float)y, 2.));
				if (r.type == 'C')
				{
					if (distance <= r.rad)
						img[y * r.b_width + x] = r.cir;
				}
				else if (r.type == 'c')
				{
					if (distance >= r.rad - f_one && distance <= r.rad)
						img[y * r.b_width + x] = r.cir;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &r.type, &r.cen_x, &r.cen_y, &r.rad, &r.cir);
	}
	if (read != -1)
	{
		free(img);
		return (ft_putstr("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < r.b_height)
	{
		write(1, img + y * r.b_width, r.b_width);
		write(1, "\n", 1);
		y++;
	}
	free(img);
	fclose(file);
	return (0);
}
