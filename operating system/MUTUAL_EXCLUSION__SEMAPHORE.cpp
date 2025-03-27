#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 10
int n;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty, full, mutex;

void *producer(void *arg) {
    int item,i;
    for(i=0;i<n;i++){
        item = rand() % 100;  

        sem_wait(&empty);  
        sem_wait(&mutex);  

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Produced item %d\n", item);

        sem_post(&mutex);  
        sem_post(&full);  
    }
}

void *consumer(void *arg) {
    int item,i;
    for(i=0;i<n;i++){
        sem_wait(&full);   
        sem_wait(&mutex);  

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumed item %d\n", item);

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    pthread_t prod_tid, cons_tid;
    printf("Enter the number of time to produce:");
    scanf("%d",&n);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);
    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
