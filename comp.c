#include <stdio.h>
#include <string.h>
int main(){
	char* str[5] = {NULL};
	str[0] = "&";

	if (strcmp(str[0] , "&") == 0){
		printf("they arer equla\n");
	}

	else{
		printf("nope\n");
	}


}
