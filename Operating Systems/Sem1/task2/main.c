#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct  {
    int lower;
    int upper;
}Range;

void* getSum ( void* arg ) {
    Range* range = arg;
    long long sum = 0;
    for (int i = range->lower; i < range->upper; i++) {
        sum += i;
    }
    printf(" a sum: %lld\n", sum);

    long long* result = malloc(sizeof(sum));
    *result = sum;
    return result;
}

int main () {
    short int num_threads = 4;
    pthread_t list_threads [num_threads];
    Range list_structs[num_threads];

    printf("Enter a number: ");
    int value;
    scanf("%d", &value);

    int start = 1;
    int end = value/num_threads;

    for ( int i = 0; i < num_threads; i++) {
        list_structs[i].lower = start;
        list_structs[i].upper = end;

        pthread_create(&list_threads[i], NULL, getSum, &list_structs[i]);
        start = end;
        end += end;
        if (end > value) end = value + 1;
    }

    long long total = 0;
    for ( int i = 0; i < num_threads; i++) {
        long long* result;
        pthread_join(list_threads[i], (void**)&result);
        total += *result;
    }
    printf(" Total sum: %lld\n", total);
    return 0;
}