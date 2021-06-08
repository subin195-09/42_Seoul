#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define N			5
#define THINKING	2
#define HUNGRY		1
#define EATING		0
#define LEFT		(philo_num + 4) % N
#define RIGHT		(philo_num + 1) % N

int		state[N];
int		philo[N] = {0, 1, 2, 3, 4};
sem_t	sema;
sem_t	S[N];

void	test(int philo_num)
{
	if (state[philo_num] == HUNGRY &&
		state[LEFT] != EATING &&
		state[RIGHT] != EATING)
	{
		state[philo_num] = EATING;
		usleep(1000 * 100);
		printf("Philosopher %d takes fork %d, %d\n", philo_num + 1, LEFT + 1, RIGHT + 1);
		printf("Philosophers %d is Eating\n", philo_num + 1);
		sem_post(&S[philo_num]);
	}
}

void	take_fork(int philo_num)
{
	sem_wait(&sema);
	state[philo_num] = HUNGRY;
	printf("Philosopher %d is Hungry\n", philo_num + 1);
	test(philo_num);
	sem_post(&sema);
	sem_wait(&S[philo_num]);
	usleep(1000 * 100);
}

void	return_fork(int philo_num)
{
	sem_wait(&sema);
	state[philo_num] = THINKING;
	printf("Philosopher %d return %d, %d fork\n", philo_num + 1, LEFT + 1, RIGHT + 1);
	printf("Philosopher %d is thinking\n", philo_num + 1);
	test(LEFT);
	test(RIGHT);
	sem_post(&sema);
}

void	*philosopher(void *arg)
{
	int	*philo_num;

	philo_num = (int *)arg;
	while (1)
	{
		usleep(1000 * 100);
		take_fork(*philo_num);
		usleep(0000 * 100);
		return_fork(*philo_num);
	}
}

int		main(void)
{
	int			i;
	pthread_t	thread[N];

	// sem_init(&sema, 0, 1);
	// for (i = 0; i < N; i++)
	// 	sem_init(&S[i], 0, 0);
	for (i = 0; i < N; i++)
	{
		pthread_create(&thread[i], 0, philosopher, &philo[i]);
		printf("Philosopher %d is thinking\n", i + 1);
	}
	for (i = 0; i < N; i++)
		pthread_join(thread[i], 0);
}