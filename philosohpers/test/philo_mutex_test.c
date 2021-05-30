#include <stdio.h>
#include <unistd.h>
#include <pthread.h>   
 
#define NUM_THREADS 5
 
pthread_mutex_t mutexes[NUM_THREADS];
pthread_cond_t conditionVars[NUM_THREADS];
 
int permits[NUM_THREADS];
pthread_t tids[NUM_THREADS];
 
void pickup_forks(int philosopher_number) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    while (permits[philosopher_number%NUM_THREADS] == 0) {
        pthread_cond_wait(&conditionVars[philosopher_number%NUM_THREADS], &mutexes[philosopher_number%NUM_THREADS]);
    }
    permits[philosopher_number%NUM_THREADS] = 0;
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
}
 
void return_forks(int philosopher_number) {
    pthread_mutex_lock(&mutexes[philosopher_number%NUM_THREADS]);
    permits[philosopher_number%NUM_THREADS] = 1;
    pthread_cond_signal(&conditionVars[philosopher_number%NUM_THREADS]);
    pthread_mutex_unlock(&mutexes[philosopher_number%NUM_THREADS]);
     
}
 
void* Philosopher(void *arg) {
    int philosopher_number;
    philosopher_number = (int)arg;
    
    // write(1, "not_odd\n", 8);
    // printf("function in : %d\n", philosopher_number);
    // pickup left fork
    pickup_forks(philosopher_number);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
     
    // pickup right fork
    pickup_forks(philosopher_number+1);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
     
    printf("philosopher(%d) starts eating \n", philosopher_number);
    usleep(1000 * 1000);
    printf("philosopher(%d) finishes eating \n", philosopher_number);
 
    // putdown right fork
    return_forks(philosopher_number + 1);
    printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    // putdown left fork
    return_forks(philosopher_number);
    printf("philosopher(%d) put down the fork(%d).\n", philosopher_number, philosopher_number);
 
    return NULL;
}
 
void * OddPhilosopher(void * arg) {
    int philosopher_number;
    philosopher_number = (int)arg;
 
    // write(1, "odd\n", 4);
    // printf("function in : %d\n", philosopher_number);
    // pickup right fork
    pickup_forks(philosopher_number + 1);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    // pickup left fork
    pickup_forks(philosopher_number);
    printf("philosopher(%d) picks up the fork(%d).\n", philosopher_number, philosopher_number);
 
    printf("philosopher(%d) starts eating \n", philosopher_number);
    usleep(1000 * 1000);
    printf("philosopher(%d) finishes eating \n", philosopher_number);
 
    // putdown left fork
    return_forks(philosopher_number);
    printf("philosopher(%d) puts down the fork(%d).\n", philosopher_number, philosopher_number);
 
    // putdown right fork
    return_forks(philosopher_number + 1);
    printf("philosopher(%d) puts down the fork(%d).\n", philosopher_number, (philosopher_number + 1) % NUM_THREADS);
 
    return NULL;
}
 
int main() {
    int i;
 
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_mutex_init(&mutexes[i], NULL);
        pthread_cond_init(&conditionVars[i], NULL);
        permits[i] = 1;
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0)
        {
            pthread_create(&tids[i], NULL, Philosopher, (void *)((long)i));
        }
        else
        {
            pthread_create(&tids[i], NULL, OddPhilosopher, (void *)((long)i));
        }
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