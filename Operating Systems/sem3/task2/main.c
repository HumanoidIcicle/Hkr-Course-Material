#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

void append(Node **head, int value) {
    Node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    Node *list = NULL;

    for (int i = 0; i < 5; i++) {
        append(&list, i);
    }

    print_list(list); /* Memory leak if not freed
        0 -> 1 -> 2 -> 3 -> 4 -> NULL
        ==4049==
        ==4049== HEAP SUMMARY:
        ==4049==     in use at exit: 80 bytes in 5 blocks
        ==4049==   total heap usage: 6 allocs, 1 frees, 1,104 bytes allocated
        ==4049==
        ==4049== 80 (16 direct, 64 indirect) bytes in 1 blocks are definitely lost in loss record 2 of 2
        ==4049==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
        ==4049==    by 0x1091E1: create_node (main.c:10)
        ==4049==    by 0x10921D: append (main.c:17)
        ==4049==    by 0x109343: main (main.c:52)
        ==4049==
        ==4049== LEAK SUMMARY:
        ==4049==    definitely lost: 16 bytes in 1 blocks
        ==4049==    indirectly lost: 64 bytes in 4 blocks
        ==4049==      possibly lost: 0 bytes in 0 blocks
        ==4049==    still reachable: 0 bytes in 0 blocks
        ==4049==         suppressed: 0 bytes in 0 blocks
        ==4049==
        ==4049== For lists of detected and suppressed errors, rerun with: -s
        ==4049== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
    */
    free_list(list);/* Memory error detector result:
    0 -> 1 -> 2 -> 3 -> 4 -> NULL
    ==3271==
    ==3271== HEAP SUMMARY:
    ==3271==     in use at exit: 0 bytes in 0 blocks
    ==3271==   total heap usage: 6 allocs, 6 frees, 1,104 bytes allocated
    ==3271==
    ==3271== All heap blocks were freed -- no leaks are possible
    ==3271==
    ==3271== For lists of detected and suppressed errors, rerun with: -s
    ==3271== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 */

    return 0;
}
