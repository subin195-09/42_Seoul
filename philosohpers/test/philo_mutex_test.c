#include <stdio.h>
#include <unistd.h>
#include <pthread.h>   
 
#define NUM_THREADS 5
#define MUST_EAT    2
 
pthread_mutex_t mutexes[NUM_THREADS];
pthread_cond_t conditionVars[NUM_THREADS];
 
int permits[NUM_THREADS];
pthread_t tids[NUM_THREADS];
 
void pickup_forks(int philosopher_number, int real_num) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    while (permits[philosopher_number%NUM_THREADS] == 1) {
        pthread_cond_wait(&conditionVars[philosopher_number%NUM_THREADS], &mutexes[philosopher_number%NUM_THREADS]);
    }
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, real_num);
    permits[philosopher_number%NUM_THREADS] = 1;
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
}
 
void return_forks(int philosopher_number) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    permits[philosopher_number%NUM_THREADS] = 0;
    pthread_cond_signal(&conditionVars[philosopher_number%NUM_THREADS]);
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
     
}
 
void* Philosopher(void *arg) {
    int philosopher_number;
    int count;

    philosopher_number = (int)arg;
    count = -1;
    while (++count < MUST_EAT)
    {
        // pickup_forks(philosopher_number, philosopher_number);
        // pickup_forks(philosopher_number+1, philosopher_number);
        if (philosopher_number != 4)
        {
            // pickup left fork
            // printf("left %d\n", philosopher_number);
            pickup_forks(philosopher_number, philosopher_number);

            // pickup right fork
            // printf("right %d\n", philosopher_number);
            pickup_forks(philosopher_number+1, philosopher_number);
            // printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
        }
        else
        {
            // pickup right fork
            // printf("right %d\n", philosopher_number);
            pickup_forks(philosopher_number+1 , philosopher_number);
            // printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);

            // pickup left fork
            // printf("left %d\n", philosopher_number);
            pickup_forks(philosopher_number, philosopher_number);
            // printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
        }

        printf("philosopher(%d) starts eating \n", philosopher_number);
        // time_to_eat
        // usleep(1000 * 1000);
        printf("philosopher(%d) finishes eating \n", philosopher_number);
    
        // putdown right fork
        return_forks(philosopher_number + 1);
        printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
    
        // putdown left fork
        return_forks(philosopher_number);
        printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, philosopher_number);

        // add : time_to_sleepp
        printf("philosopher(%d) is sleeping(%d).\n", philosopher_number, philosopher_number);
        // usleep(1000 * 1000);

        // add : thinking
        printf("philosopher(%d) is thinking(%d).\n", philosopher_number, philosopher_number);
    }
    return NULL;
}
 
int main() {
    int i;
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_init(&mutexes[i], NULL);
        pthread_cond_init(&conditionVars[i], NULL);
        permits[i] = 0;
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        // if (i % 2 == 0)
        // {
        //     pthread_create(&tids[i], NULL, Philosopher, (void *)((long)i));
        // }
        // else
        // {
        //     pthread_create(&tids[i], NULL, OddPhilosopher, (void *)((long)i));
        // }
        pthread_create(&tids[i], NULL, Philosopher, (void *)((long)i));
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(tids[i], NULL);
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_destroy(&mutexes[i]);
        pthread_cond_destroy(&conditionVars[i]);
    }
 
    return 0;
}