#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5 // Number of philosophers

pthread_t t[NUM_PHILOSOPHERS];
pthread_mutex_t forks[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", id);

        // Grab forks
        printf("Philosopher %d wants to pick up the left fork (%d).\n", id, left);
        pthread_mutex_lock(&forks[left]);
        printf("Philosopher %d picked up the left fork (%d).\n", id, left);
        printf("Philosopher %d wants to pick up the right fork (%d).\n", id, right);
        pthread_mutex_lock(&forks[right]);
        printf("Philosopher %d picked up the right fork (%d).\n", id, right);

        // Eating
        printf("Philosopher %d is eating.\n", id);

        // Release forks
        pthread_mutex_unlock(&forks[left]);
        printf("Philosopher %d released the left fork (%d).\n", id, left);
        pthread_mutex_unlock(&forks[right]);
        printf("Philosopher %d released the right fork (%d).\n", id, right);
       
        // Thinking
        printf("Philosopher %d is thinking.\n", id);
    }
}

int main() {
    int i;
    int ids[NUM_PHILOSOPHERS];
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_mutex_init(&forks[i], NULL);
        pthread_create(&t[i], NULL, philosopher, &ids[i]);
    }
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(t[i], NULL);
    }
    return 0;
}
