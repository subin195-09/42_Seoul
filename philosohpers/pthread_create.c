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
        printf("thread name : %s, tid : %x\n", (char *)data, (unsigned int)tid);
        usleep(1000 * 1000);
    }
    return (0);
}

int     main(void)
{
    pthread_t   pthread;
    int         thr_id;
    int         status;
    char        p1[] = "thread_skim";
    char        p2[] = "thread_main";

    thr_id = pthread_create(&pthread, 0, p_function, (void *)p1);
    if (thr_id < 0)
    {
        perror("thread error\n");
        exit(EXIT_FAILURE);
    }
    p_function((void *)p2);
    printf("present id : %x\n", (unsigned int)pthread_self());
    printf("end\n");
    return (0);
}