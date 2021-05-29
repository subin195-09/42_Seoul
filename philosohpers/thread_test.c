#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void    *thread(void *varg)
{
    printf("hello %s\n", (char *)varg);
    return (NULL);
}

int     main(void)
{
    pthread_t   tid;

    pthread_create(&tid, NULL, thread, (void *)"skim");
    pthread_join(tid, NULL);
    exit(0);
}