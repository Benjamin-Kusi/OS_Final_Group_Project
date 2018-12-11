// Tests for concurrent linked list

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "concurrent_data_structures.h"

list_t linked_list;

void * thread_insert(){
    for (int i = 0; i < 10000; ++i) {
        List_Insert(&linked_list, i+10);
    }

    return NULL;
}

void * thread_delete(){
    for (int i = 0; i < 10000; ++i) {
        List_Delete(&linked_list, i+10);
    }

    return NULL;
}

int main(int argc, char *argv[]){
    printf("Initializing linked list\n");
    List_Init(&linked_list);

    printf("Initial length of list: %d\n", List_Length(&linked_list));

    printf("Inserting 10 items into the linked list\n");

    for (int i = 0; i < 10; ++i) {
        List_Insert(&linked_list, i);
    }

    printf("Finished inserting items\n");


    printf("Expected length = 10\n");
    printf("Length after inserting: %d\n\n", List_Length(&linked_list));

    printf("Deleting one item\n");
    List_Delete(&linked_list, 0);

    printf("Length of list after delete: %d\n", List_Length(&linked_list));

    printf("Performing multithreaded insert. 10000 inserts each for 2 threads\n");

    pthread_t p1, p2;
    pthread_create(&p1, NULL, thread_insert, "A");
    pthread_create(&p2, NULL, thread_insert, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Expected length = 20009\n");
    printf("Length after insert: %d\n", List_Length(&linked_list));


    printf("Performing multithreaded delete. 10000 deletes each for 2 threads\n");

    pthread_create(&p1, NULL, thread_delete, "A");
    pthread_create(&p2, NULL, thread_delete, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Expected length = 9\n");
    printf("Length after concurrent deletes: %d\n", List_Length(&linked_list));

    return 0;
}
