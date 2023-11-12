#include <stdio.h>
#include <pthread.h>
pthread_mutex_t fork1, fork2, fork3;

void *philosopher1(void *param) {
    while(1){
    printf("Philosopher 1 wants to pick up fork 1\n");
    pthread_mutex_lock(&fork1);
    printf("Philosopher 1 picked up fork 1\n");
    
    printf("Philosopher 1 wants to pick up fork 2\n");
    pthread_mutex_lock(&fork2);
    printf("Philosopher 1 picked up fork 2\n");

    printf("\n* Philosopher 1 is eating *\n\n");

    pthread_mutex_unlock(&fork2);
    printf("Philosopher 1 put down fork 2\n");
 
    pthread_mutex_unlock(&fork1);
    printf("Philosopher 1 put down fork 1\n");

    printf("\n* Philosopher 1 is thinking *\n\n");
    }
    pthread_exit(NULL);
}
void *philosopher2(void *param) {
    while(1){
    printf("\t\tPhilosopher 2 wants to pick up fork 2\n");
    pthread_mutex_lock(&fork2);
    printf("\t\tPhilosopher 2 picked up fork 2\n");

    printf("\t\tPhilosopher 2 wants to pick up fork 3\n");
    pthread_mutex_lock(&fork3);
    printf("\t\tPhilosopher 2 picked up fork 3\n");

    printf("\n\t\t* Philosopher 2 is eating *\n\n");

    pthread_mutex_unlock(&fork3);
    printf("\t\tPhilosopher 2 put down fork 3\n");
    
    pthread_mutex_unlock(&fork2);
    printf("\t\tPhilosopher 2 put down fork 2\n");

    printf("\n\t\t* Philosopher 2 is thinking *\n\n");
    }
    pthread_exit(NULL);
}
void *philosopher3(void *param) {
    while(1){
    printf("\t\t\t\tPhilosopher 3 wants to pick up fork 3\n");
    pthread_mutex_lock(&fork3);
    printf("\t\t\t\tPhilosopher 3 picked up fork 3\n");
    
    printf("\t\t\t\tPhilosopher 3 wants to pick up fork 1\n");
    pthread_mutex_lock(&fork1);  
    printf("\t\t\t\tPhilosopher 3 picked up fork 1\n");
    
    printf("\n\t\t\t\t* Philosopher 3 is eating *\n\n");
     
    pthread_mutex_unlock(&fork1);
    printf("\t\t\t\tPhilosopher 3 put down fork 1\n");
    
    pthread_mutex_unlock(&fork3);
    printf("\t\t\t\tPhilosopher 3 put down fork 3\n");
    
    printf("\n\t\t\t\t* Philosopher 3 is thinking *\n\n");
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t t1, t2, t3;

    pthread_mutex_init(&fork1, NULL);
    pthread_mutex_init(&fork2, NULL);
    pthread_mutex_init(&fork3, NULL);

    pthread_create(&t1, NULL, philosopher1, NULL);
    pthread_create(&t2, NULL, philosopher2, NULL);
    pthread_create(&t3, NULL, philosopher3, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}
