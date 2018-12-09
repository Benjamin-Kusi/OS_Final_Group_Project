#include <stdio.h>
#include <stdlib.h>

typedef struct __counter_t{

	int value;
}
counter_t;

void init(counter_t *c){
	c-> value = 0;
}

void increment (counter_t *c){
	c->value++;
}

void decrement (counter_t *c){
	c ->value--;
}

int get(counter_t *c){
	return c -> value;
}

int main(){
	
	counter_t * k;
	k = (struct counter_t *) malloc(sizeof(struct counter_t*));
	k->value = 0;
	printf("works\n");

}
