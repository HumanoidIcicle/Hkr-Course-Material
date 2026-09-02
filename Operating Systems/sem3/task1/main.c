#include <stdio.h>
#include <stdlib.h>

int* stack_array(void) {
    int data[5] = {1, 2, 3, 4, 5};
    printf("\nStack array address: %p\n", (void *)data);
    return data;
}

void heap_array(void) {
    int *data = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        data[i] = i + 1;
    }
    printf("\nHeap array address: %p\n", (void *)data);
    free(data);
}

int main(void) {
    int* stack = stack_array();

    printf("\nReturned stack address: %p\n", (void *)stack); /*
     * Address of array on the stack exists only if printed while
     * the function is still running.
     * After the function terminates, the array is popped off the
     * stack so if we try to return its address, nothing exists so
     * prints im guessing default/null which is 00000000000.
     */
    heap_array(); /* Arrays have different addresses on heap and stack */
    return 0;
}
