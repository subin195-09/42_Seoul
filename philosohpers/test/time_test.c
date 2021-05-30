#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int     main(void)
{
    struct timeval  s_time, e_time;
    double          dif_tv_sec;
    double          dif_tv_usec;

    gettimeofday(&s_time, 0);
    usleep(1000 * 1000); // 1초
    gettimeofday(&e_time, 0);
    dif_tv_sec = e_time.tv_sec - s_time.tv_sec;
    dif_tv_usec = (e_time.tv_usec - s_time.tv_usec) / 1000000;
    printf("diff sec : %f\n", dif_tv_sec);
    printf("diff usec : %f\n", dif_tv_usec);
    return (0);
}