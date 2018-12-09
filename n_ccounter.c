#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct __counter_t{
	int value;
}counter_t;

void init (counter_t *c){
	c -> value = 0;
}

void increment(counter_t *c){
	c->value++;
}

void decrement (counter_t *c){
	c->value--;
}

int get(counter_t *c ){
	int rc = c ->value;
	return rc;
}

counter_t p;

void * first_thread(){

	for (int i =1; i <= 20000; i++){
		int val = get(&p);
//		printf("%i", val);
//		printf ("\n");
		increment(&p);
	}
//	return NULL;
}

void * second_thread(){

	for (int i =1; i <= 20000; i++){
		int val = get(&p);
//		printf("%i", val);
//		printf ("\n");
		increment(&p);
	}
//	return NULL;
}

void * third_thread(){

	for (int i =1; i <= 20000; i++){
		int val = get(&p);
//		printf("%i", val);
//		printf ("\n");
		increment(&p);
	}
//	return NULL;
}


int main(){


	init(&p);
	pthread_t id1;
	int t1;
	pthread_t id2;
	int t2;
	pthread_t id3;
	int t3;

	t1 = pthread_create(&id1, NULL, first_thread, "A");
	t2 = pthread_create(&id2, NULL, second_thread, "B");
	t3 = pthread_create(&id3, NULL, third_thread, "C");

	pthread_join(id1, NULL);

	pthread_join(id2, NULL);

	pthread_join(id3, NULL);

	int val = get(&p);
	printf("%i", val);
	printf ("\n");

	return 0;
}
