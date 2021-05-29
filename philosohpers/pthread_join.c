#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    *p_function(void *data)
{
    pthread_t   tid;
    int         i;

    tid = pthread_self();
    i = -1;
    while (++i < 3)
    {
        printf("(%d / 3) thread name : %s, tid : %x\n", i + 1, (char *)data, (unsigned int)tid);
        usleep(1000 * 1000);
    }
    return ((void *)"skim");
}

int     main(void)
{
    pthread_t   pthread;
    int         thr_id;
    int         status;
    char        p1[] = "thread_skim";
    char        *result;

    thr_id = pthread_create(&pthread, 0, p_function, (void *)p1);
    if (thr_id < 0)
    {
        perror("thread error\n");
        exit(EXIT_FAILURE);
    }
    pthread_join(pthread, (void *)&result);
    printf("result : %s\n", result);
    printf("end\n");
    return (0);
}