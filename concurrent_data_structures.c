// concurrent data structures


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

#define BUCKETS (101)


// linked list ============================================================
typedef struct __node_t {
    int key;
    struct __node_t *next;
} node_t;

typedef struct __list_t {
    int length;
    node_t *head;
    pthread_mutex_t lock;
} list_t;

void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->lock, NULL);
}

int List_Insert(list_t *L, int key) {
    pthread_mutex_lock(&L->lock);
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("malloc");
        pthread_mutex_unlock(&L->lock);
        return -1; // fail
    }

    new_node->key  = key;
    new_node->next = L->head;
    L->head   = new_node;

    L->length++;
    pthread_mutex_unlock(&L->lock);

    return 0; // success
}

int List_Delete(list_t *L, int key){
    pthread_mutex_lock(&L->lock);

    node_t h = *L->head;

    if (h.key == key){
        L->head = h.next;
        L->length--;
        pthread_mutex_unlock(&L->lock);

        return 0;
    } else if (h.next != NULL){
        node_t current = *h.next;
        node_t previous = h;

        do {
            if (current.key == key){
                previous.next = current.next;
                L->length--;
                pthread_mutex_unlock(&L->lock);

                return 0;
            }
            current = *current.next;
        } while (current.next != NULL);

        if (current.key == key){
            previous.next = current.next;
            L->length--;
            pthread_mutex_unlock(&L->lock);

            return 0;
        }
    }
    pthread_mutex_unlock(&L->lock);

    return 0;
}

int List_Lookup(list_t *L, int key){
    pthread_mutex_lock(&L->lock);
    node_t *curr = L->head;
    while (curr) {
        if (curr->key == key) {
            pthread_mutex_unlock(&L->lock);
            return 0; // success
        }
        curr = curr->next;pthread_mutex_unlock(&L->lock);
        return -1; // failure
    }

    return 0;
}

int List_Length(list_t *L){
    pthread_mutex_lock(&L->lock);
    int len = L->length;
    pthread_mutex_unlock(&L->lock);

    return len;

}
