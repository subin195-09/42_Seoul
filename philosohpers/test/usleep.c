#include <stdio.h>
#include <unistd.h>

int     main(void)
{
    printf("0\n");
    usleep(1000 * 1000);
    printf("1\n");
    usleep(1000 * 1000);
    printf("2\n");
}