#include <stdio.h>
# include <pthread.h>

void * print_message ( void * arg ) {
    int id = *(int*) arg ;
    printf ( " Hello from thread: %d\n" , id ) ;
    return NULL ;
}

int main () {
    pthread_t threads [4];
    int ids [4] = {0 , 1 , 2 , 3};

    for ( int i = 0; i < 4; i ++) {
        pthread_create (& threads [ i ] , NULL , print_message , &ids[i]) ;
    }

    for ( int i = 0; i < 4; i ++) {
        pthread_join ( threads [ i ] , NULL ) ;
    }

    return 0;
}