#include <stdio.h>
#include <pthread.h>
/*
//RACE CONDITION
int sum = 0;
int nts = 10;
int change = 100000;

void* func(void* arg) {
    for (int i = 0; i<change;i++) sum++;
    return NULL;
}

int main() {
    pthread_t all[nts];
    for (int i = 0; i<nts; i++) pthread_create(&all[i], NULL, func, NULL);
    for (int i = 0; i<nts; i++) pthread_join(all[i], NULL);

    printf("Expected: %d\n", nts*change);
    printf("Calculated: %d\n", sum);
    return 0;
}
*/

int sum = 0;
int times = 1000000;

void* func(void* arg) {
    int* id = arg;
    int before = sum;
    for (int i = 0; i<times; i++) sum++;
    printf("Thread %d read: %d\n", *id, before);
    printf("Returned sum: %d\n\n", sum);
    return NULL;
}

int main() {
    int num = 4;
    pthread_t ts[num];
    int ids[num];

    for (int i = 0; i < num; i++) {
        ids[i] = i;
        pthread_create(&ts[i], NULL, func, &ids[i]);
    }

    for (int i = 0; i < num; i++) {
        pthread_join(ts[i], NULL);
    }

    printf("Final sum: %d\n", sum);
    printf("Expected: %d\n", num * times);
    return 0;
}