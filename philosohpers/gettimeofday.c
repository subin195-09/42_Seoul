#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int     main(void)
{
    struct timeval my_time;

    gettimeofday(&my_time, NULL);
    printf("%ld, %d\n", my_time.tv_sec, my_time.tv_usec);
    printf("%ld, %d\n", my_time.tv_sec * 1000000, my_time.tv_usec);
    printf("relative time : %ld\n", my_time.tv_sec * 1000000 + my_time.tv_usec);
    return (0);
}