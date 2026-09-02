#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;

int delay() {
    int d = rand()% 10000000+1;
    printf("----Delayed by: %d\n",d );
    return d;
}

void* producer(void* arg) {
    int* id = arg;
    int item = 0;
    while (1) { //make items indefinitely
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) /* Checks if buffer is full, if it is
             * calls the pwait which unlocks the mutex,
             * puts the thread to sleep,
             * re-locks the mutex when awakened,
             * using while allows threads to wake up without being signaled.
             */
            pthread_cond_wait(&not_full, &mutex); //Atomic instruction
        buffer[count++] = item++; //Producer adds an item to buffer
        printf("\nProducer - %d - 'made' | Item: %d\n",*id, item);
        pthread_cond_signal(&not_empty); /* Condition variable to signal when buffer is not empty
         * wakes up consumer waiting for items, happens while still locked
         */

        pthread_mutex_unlock(&mutex); //unlock so other threads proceed
        usleep(delay()); //Slow down for readability
    }
}
void* consumer (void*arg) {
    int* id = arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        while (count == 0)
            pthread_cond_wait(&not_empty, &mutex);
        int item = buffer[--count]; //Consumes item at last index
        printf("\nConsumer - %d - 'consumed' | Item: %d\n",*id, item);
        pthread_cond_signal(&not_full); /* Condition variable to signal when buffer is not full
         * to wake up producers if it is waiting.
         */
        pthread_mutex_unlock(&mutex);
        usleep(1500000);
    }
}

int main() {
    srand(time(NULL));
    int num_of_threads = 4;
    pthread_t prod[num_of_threads], cons[num_of_threads];
    int ids[num_of_threads];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    for (int i = 0; i < num_of_threads; i++) {
        ids[i] = i;
        pthread_create(&prod[i], NULL, producer, &ids[i]);
        pthread_create(&cons[i], NULL, consumer, &ids[i]);
    }

    for (int i = 0; i < num_of_threads; i++) {
        pthread_join(prod[i], NULL);
        pthread_join(cons[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}