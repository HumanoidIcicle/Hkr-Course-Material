#include <stdio.h>
#include <pthread.h>

//RACE CONDITION fixed with mutex
int counter = 0;
int nts = 5;
int change = 1000000;

pthread_mutex_t mutex;

void* func(void* arg) {
    for (int i = 0; i < change; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t all[nts];
    for (int i = 0; i<nts; i++) pthread_create(&all[i], NULL, func, NULL);
    for (int i = 0; i<nts; i++) pthread_join(all[i], NULL);

    printf("Expected: %d\n", nts*change);
    printf("Calculated: %d\n", counter);
    pthread_mutex_destroy(&mutex);
    return 0;
}