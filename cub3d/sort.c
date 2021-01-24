#include <stdio.h>
#define numSprite 5

int		spriteOrder[numSprite];
double	spriteDistance[numSprite];

void	sortSprie(void)
{
	int		tmp;
	double	max = 0;

	for(int i = 0; i < numSprite - 1; i++)
	{
		max = spriteDistance[i];
		for(int j = i + 1; j < numSprite; j++)
		{
			if (max < spriteDistance[j])
			{
				max = spriteDistance[j];
				tmp = spriteOrder[i];
				spriteOrder[i] = spriteOrder[j];
				spriteOrder[j] = tmp;
			}
		}
	}
}

void	print_arr(int *arr)
{
	for(int i = 0; i < numSprite; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void	print_arr_f(double *arr)
{
	for(int i = 0; i < numSprite; i++)
		printf("%f ", arr[i]);
	printf("\n");
}

int main(void)
{
	for(int i = 0; i < numSprite; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = i * i;
	}
	print_arr(spriteOrder);
	print_arr_f(spriteDistance);
	sortSprie();
	print_arr(spriteOrder);
	print_arr_f(spriteDistance);
}
