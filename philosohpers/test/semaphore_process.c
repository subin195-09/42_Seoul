#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/wait.h>

int     main(void)
{
    pid_t   pid;
    int     num;
    int     status;
    sem_t   *sem;

    sem_unlink("skim");
    sem = sem_open("skim", O_CREAT | O_EXCL, 0644, 3);
    for (int i = 0; i < 4; i++)
    {
        pid = fork();
        num = i;
        if (pid == 0)
            break ;
    }
    if (pid == 0) // child
    {
        sem_wait(sem);
        for (int i = 0; i < 3; i++)
        {
            printf("%d critical section\n", num);
            usleep(1000 * 1000);
        }
        sem_post(sem);
    }
    else // parent
    {
        while (wait(&status) > 0);
        printf("child end\n");
    }
}