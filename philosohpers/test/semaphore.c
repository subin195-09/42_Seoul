#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t   *sem;
int     count = 0;

void    *routine(void *num)
{
	sem_wait(sem);
	for (int i = 0; i < 3; i++)
	{
		printf("%d: use sem (count : %d)\n", *(int *)num, count++);
		usleep(1000 * 100);
	}
	sem_post(sem);
	return (num);
}

int     main(void)
{
	int         ret;
	pthread_t   tid[4];
	int         num[4];

	sem = sem_open("skim", O_CREAT | O_EXCL, 0644, 3); // value를 1로 한다면 mutex와 같은 역할을 한다
	if (sem == SEM_FAILED)
	{
		printf("sem error\n");
		return (-1);
	}
	for (int i = 0; i < 4; i++)
	{
		num[i] = i;
		pthread_create(&tid[i], NULL, routine, (void *)&num[i]);
		usleep(100);
	}
	for (int i = 0; i < 4; i++)
		pthread_join(tid[i], NULL);
	ret = sem_close(sem);
	printf("sem_close : %d\n", ret);
	ret = sem_unlink("skim");
	printf("sem_unlink : %d\n", ret);
	return (0);
}