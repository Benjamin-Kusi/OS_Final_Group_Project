#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct __counter_t{
	int value;
	pthread_mutex_t  lock;
}counter_t;


void init (counter_t *c){
	c->value = 0;
	pthread_mutex_init(&c->lock, NULL);
}

void increment (counter_t *c){
	pthread_mutex_lock(&c->lock);
	c->value++;
	pthread_mutex_unlock(&c->lock);
}

void decrement (counter_t *c){
	pthread_mutex_lock(&c->lock);
	c->value--;
	pthread_mutex_unlock(&c->lock);
}

int get(counter_t *c){

	pthread_mutex_lock(&c->lock);
	int rc = c->value;
	pthread_mutex_unlock(&c->lock);
	return rc;

}

counter_t p;
//init(&p);

void * first_thread(){
//	init(&p);

	for (int j = 1; j <= 20000; j++){
		int val = get(&p);
//		printf("%i", val);
//		printf("\n");
		increment(&p);
	}
	return NULL;
}

void * second_thread(){
	for (int i = 1; i <= 20000; i++){
		int val = get(&p);
//		printf("%i", val);
//		printf("\n");
		increment(&p);
	}
	return NULL;

}

void * third_thread(){
	for (int i = 1; i <= 20000; i++){
		int val = get(&p);
//		printf("%i", val);
//		printf("\n");
		increment(&p);
	}
	return NULL;

}
//	init(&p);


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
	int cal = get(&p);
	printf("%i", cal);
	printf("\n");
//	return 0;
}
