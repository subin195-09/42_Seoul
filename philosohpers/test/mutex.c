#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t m;
int             cnt = 0;

void    *count(void *arg)
{
    pthread_mutex_lock(&m);
    for (int i = 0; i < 10; i++)
    {
        printf("%s cnt : %d\n", (char *)arg, cnt);
        cnt++;
        usleep(1000 * 100);
    }
    pthread_mutex_unlock(&m);
    return (0);
}

int     main(void)
{
    pthread_t   t1, t2;

    pthread_mutex_init(&m, NULL);

    pthread_create(&t1, NULL, count, (void *)"thread 1");
    pthread_create(&t2, NULL, count, (void *)"thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&m);
}