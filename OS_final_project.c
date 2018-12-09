#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define BUCKETS (101)
// #include "concurrent_data_structures.h"

// basic node structure
typedef struct __node_t {
    int key;
    struct __node_t *next;
} node_t;

// basic list structure (one used per list)
typedef struct __list_t {
    int length;
    node_t *head;
    pthread_mutex_t lock;
} list_t;

typedef struct __hash_t {
	list_t lists[BUCKETS];
} hash_t;


//defining all functions for the linked list to be used in implementing the hash table
void List_Init(list_t *L) {
    L->head = NULL;
    pthread_mutex_init(&L->lock, NULL);
}

//inserting into the list
int List_Insert(list_t *L, int key) {
    pthread_mutex_lock(&L->lock);
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        perror("malloc");
        pthread_mutex_unlock(&L->lock);
        return -1; // failss
    }

    new_node->key  = key;
    new_node->next = L->head;
    L->head   = new_node;

    L->length++;
    pthread_mutex_unlock(&L->lock);

    return 0; // success
}

int List_Lookup(list_t *L, int key) {
	int rv = -1;
	pthread_mutex_lock(&L->lock);
	node_t *curr = L->head;
	while (curr) {
		if (curr->key == key) {
			rv = 0;
			break;
		}
		curr = curr->next;
	}
	pthread_mutex_unlock(&L->lock);
	return rv; // now both success and failure
}


int List_Delete(list_t *L, int key) {
	int rv = -1;
	pthread_mutex_lock(&L->lock);
	node_t *curr = L->head;
	while (curr) {
		if (curr->key == key) {
			rv = 0;
			curr = NULL;
			break;
		}
		curr = curr->next;
	}
	pthread_mutex_unlock(&L->lock);
	return rv; // now both success and failure
}


void Hash_Init(hash_t *H) {
	int i;
	for (i = 0; i < BUCKETS; i++) {
		List_Init(&H->lists[i]);
	}
	printf("%s\n", "Hash table initializing was successfull.");
}


int Hash_Insert(hash_t *H, int key) {
	int bucket = key % BUCKETS;
	return List_Insert(&H->lists[bucket], key);
}


int Hash_Lookup(hash_t *H, int key) {
	int bucket = key % BUCKETS;
	return List_Lookup(&H->lists[bucket], key);
}

void Hash_Delete(hash_t *H, int key) {
	int bucket = key % BUCKETS;
	List_Delete(&H->lists[bucket], key);
}

int main(int argc, char *argv[]){
	hash_t hash_key;

	//initializing the hash table
	printf("%s\n", "Initializing the hash table");
	Hash_Init(&hash_key);

	//inserting 10 items in the hash table
	printf("%s\n", "Inserting ten items into the hash table.");
	for (int i = 1; i < 15; ++i){
		Hash_Insert(&hash_key,i);
	}

	//displaying all elements in the array
	printf("%s\n", "Printing all elements in the hash table");
	for (int i = 0; i < 15; ++i){
		Hash_Lookup(&hash_key,i);
	}

	//deleting the fifth item in the hash table
	printf("%s\n", "Deleting the 5th element in the hash table.");
	Hash_Delete(&hash_key,4);

}