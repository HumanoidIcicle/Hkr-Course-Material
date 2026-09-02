#include <stdbool.h>
#include <stdio.h>

#define MAX_LOOPS 10

void display(int arr[3][3], int r, int c) {
    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            printf("%d  ", arr[r][c]);
        }
        printf("\n");
    }
}

int main(void) {
    int processes = 3;
    int resources = 3;

    int max[3][3] = {
        {5, 3, 1},
        {2,2,2},
        {8,0,2}};

    int allocation[3][3] = {
        {0,1,0},
        {2,0,0},
        {3,0,2}};

    //Finding the need matrix
    int need [processes][3];

    for (int r = 0; r < processes; r++) {
        for (int c = 0; c < resources; c++) {
            need[r][c] = max[r][c] - allocation[r][c];
        }
    }
    display(need, processes, resources);

    //Setting the available
    int available[resources];
    for (int i = 0; i<resources;i++) {
        int temp;
        printf("Instances of resource %d: ", i);
        scanf(" %d", &temp);
        available[i] = temp;
    }

    bool finished[3] = {false, false, false};
    int limit_loops = 0;
    bool all_finished = false;

    while (!all_finished && limit_loops < MAX_LOOPS){
        int num_complete = 0;
        printf("Started loop...\n");

        for (int r = 0; r < processes; r++) {
            if (!finished[r]) {
                if (need[r][0] <= available[0] &&
                    need[r][1] <= available[1] &&
                    need[r][2] <= available[2]) {
                    printf("Process %d.\n", r);

                    for (int j = 0; j < resources; j++) {
                        available[j] = available[j] + allocation[r][j];
                    }
                    finished[r] = true;
                }
            }
        }
        all_finished = true;
        for (int i = 0; i < processes; i++)
            if (finished[i]) num_complete += 1;
        if (num_complete < processes) all_finished = false;
        limit_loops++;
    }

    if (all_finished) {
        printf("\nSystem is in a safe state\n");
    } else {
        printf("\nSystem is NOT in a safe state, "
               "possible deadlock.\n");
    }
    return 0;
}