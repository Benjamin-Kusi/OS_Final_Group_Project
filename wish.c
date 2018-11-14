
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

void * first_thread(void * arg);
void * second_thread(void * arg);
void * third_thread(void * arg);
void * fourth_thread(void * arg);
void * fifth_thread(void * arg);

void * first_thread(void *arg){
	char * and_array = (char*) arg;
	int i = 0;
	char *space_array1[6] = {NULL};
	char *split_space = strtok(and_array, " ");
	while(split_space != NULL){
		space_array1[i] = split_space;
		i++;
		split_space = strtok(NULL, " ");
	}

	char * address_one = "/usr/bin/";
	char * address_two = "/bin/";
	//allocate space in memory for paths
	char *path_one = malloc( strlen(address_one) + strlen(space_array1[0]) + 1 );
	char *path_two = malloc( strlen(address_two) + strlen(space_array1[0]) + 1 );
	

	//create full path for path one
	strcat( path_one, address_one );
	strcat( path_one, space_array1[0] );


	//create full path for path two
	strcat (path_two, address_two );
	strcat (path_two, space_array1[0] );
	if ( access( path_one, X_OK) == 0 ){

		//fill param_array
		char* const param_array[10] = {path_one, space_array1[1], space_array1[2], space_array1[3], 
				space_array1[4],space_array1[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
		//	printf( "%ld",(long)getpid());
			fprintf(stderr, "\n usrbin folder fork failed\n");
			exit(1);
		}
		else if(pid == 0){


			execv( path_one, param_array);
			//error checking
			printf("since this prints then execv didn't work");
		}
		pid = wait(NULL); 
	}
	else if (access (path_two, X_OK) == 0){

			//fill param_array
		char* const param_array[10] = {path_two, space_array1[1], space_array1[2], space_array1[3], 
				space_array1[4],space_array1[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
			fprintf(stderr, "\n bin folder-fork failed\n");
			exit(1);
		}
		else if(pid == 0){
			execv( path_two, param_array);
		}
		pid = wait(NULL);
	}


}//end of thread


void * second_thread(void * args){
	char * and_array1 = (char*) args;
	int i = 0;
	char *space_array2[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	char *split_space = strtok(and_array1, " ");
	while(split_space != NULL){
		space_array2[i] = split_space;
		i++;
		split_space = strtok(NULL, " ");
	}

	char * address_one_ = "/usr/bin/";
	char * address_two_ = "/bin/";
	//allocate space in memory for paths
	char *path_one_ = malloc( strlen(address_one_) + strlen(space_array2[0]) + 1 );
	char *path_two_ = malloc( strlen(address_two_) + strlen(space_array2[0]) + 1 );
	

	//create full path for path one
	strcat( path_one_, address_one_ );
	strcat( path_one_, space_array2[0] );


	//create full path for path two
	strcat (path_two_, address_two_ );
	strcat (path_two_, space_array2[0] );
	if ( access( path_one_, X_OK) == 0 ){

		//fill param_array
		char* const param_array[10] = {path_one_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
		//	printf( "%ld",(long)getpid());
			fprintf(stderr, "\n usrbin folder fork failed\n");
			exit(1);
		}
		else if(pid == 0){


			execv( path_one_, param_array);
			//error checking
			printf("since this prints then execv didn't work");
		}
		pid = wait(NULL); 
	}
	else if (access (path_two_, X_OK) == 0){

			//fill param_array
		char* const param_array[10] = {path_two_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
			fprintf(stderr, "\n bin folder-fork failed\n");
			exit(1);
		}
		else if(pid == 0){
			execv( path_two_, param_array);
		}
		pid = wait(NULL);
	}


}
void * third_thread(void * args){
char * and_array1 = (char*) args;
	int i = 0;
	char *space_array2[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	char *split_space = strtok(and_array1, " ");
	while(split_space != NULL){
		space_array2[i] = split_space;
		i++;
		split_space = strtok(NULL, " ");
	}

	char * address_one_ = "/usr/bin/";
	char * address_two_ = "/bin/";
	//allocate space in memory for paths
	char *path_one_ = malloc( strlen(address_one_) + strlen(space_array2[0]) + 1 );
	char *path_two_ = malloc( strlen(address_two_) + strlen(space_array2[0]) + 1 );
	

	//create full path for path one
	strcat( path_one_, address_one_ );
	strcat( path_one_, space_array2[0] );


	//create full path for path two
	strcat (path_two_, address_two_ );
	strcat (path_two_, space_array2[0] );
	if ( access( path_one_, X_OK) == 0 ){

		//fill param_array
		char* const param_array[10] = {path_one_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
		//	printf( "%ld",(long)getpid());
			fprintf(stderr, "\n usrbin folder fork failed\n");
			exit(1);
		}
		else if(pid == 0){


			execv( path_one_, param_array);
			//error checking
			printf("since this prints then execv didn't work");
		}
		pid = wait(NULL); 
	}
	else if (access (path_two_, X_OK) == 0){

			//fill param_array
		char* const param_array[10] = {path_two_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
			fprintf(stderr, "\n bin folder-fork failed\n");
			exit(1);
		}
		else if(pid == 0){
			execv( path_two_, param_array);
		}
		pid = wait(NULL);
	}

}
void * fourth_thread(void * args){
char * and_array1 = (char*) args;
	int i = 0;
	char *space_array2[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	char *split_space = strtok(and_array1, " ");
	while(split_space != NULL){
		space_array2[i] = split_space;
		i++;
		split_space = strtok(NULL, " ");
	}

	char * address_one_ = "/usr/bin/";
	char * address_two_ = "/bin/";
	//allocate space in memory for paths
	char *path_one_ = malloc( strlen(address_one_) + strlen(space_array2[0]) + 1 );
	char *path_two_ = malloc( strlen(address_two_) + strlen(space_array2[0]) + 1 );
	

	//create full path for path one
	strcat( path_one_, address_one_ );
	strcat( path_one_, space_array2[0] );


	//create full path for path two
	strcat (path_two_, address_two_ );
	strcat (path_two_, space_array2[0] );
	if ( access( path_one_, X_OK) == 0 ){

		//fill param_array
		char* const param_array[10] = {path_one_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
		//	printf( "%ld",(long)getpid());
			fprintf(stderr, "\n usrbin folder fork failed\n");
			exit(1);
		}
		else if(pid == 0){


			execv( path_one_, param_array);
			//error checking
			printf("since this prints then execv didn't work");
		}
		pid = wait(NULL); 
	}
	else if (access (path_two_, X_OK) == 0){

			//fill param_array
		char* const param_array[10] = {path_two_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
			fprintf(stderr, "\n bin folder-fork failed\n");
			exit(1);
		}
		else if(pid == 0){
			execv( path_two_, param_array);
		}
		pid = wait(NULL);
	}

}
void * fifth_thread(void * args){
char * and_array1 = (char*) args;
	int i = 0;
	char *space_array2[6] = {NULL, NULL, NULL, NULL, NULL, NULL};
	char *split_space = strtok(and_array1, " ");
	while(split_space != NULL){
		space_array2[i] = split_space;
		i++;
		split_space = strtok(NULL, " ");
	}

	char * address_one_ = "/usr/bin/";
	char * address_two_ = "/bin/";
	//allocate space in memory for paths
	char *path_one_ = malloc( strlen(address_one_) + strlen(space_array2[0]) + 1 );
	char *path_two_ = malloc( strlen(address_two_) + strlen(space_array2[0]) + 1 );
	

	//create full path for path one
	strcat( path_one_, address_one_ );
	strcat( path_one_, space_array2[0] );


	//create full path for path two
	strcat (path_two_, address_two_ );
	strcat (path_two_, space_array2[0] );
	if ( access( path_one_, X_OK) == 0 ){

		//fill param_array
		char* const param_array[10] = {path_one_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
		//	printf( "%ld",(long)getpid());
			fprintf(stderr, "\n usrbin folder fork failed\n");
			exit(1);
		}
		else if(pid == 0){


			execv( path_one_, param_array);
			//error checking
			printf("since this prints then execv didn't work");
		}
		pid = wait(NULL); 
	}
	else if (access (path_two_, X_OK) == 0){

			//fill param_array
		char* const param_array[10] = {path_two_, space_array2[1], space_array2[2], space_array2[3], 
				space_array2[4],space_array2[5] };
		pid_t pid = fork();
		//error  -- fork didn't work
		if ( pid < 0){
			fprintf(stderr, "\n bin folder-fork failed\n");
			exit(1);
		}
		else if(pid == 0){
			execv( path_two_, param_array);
		}
		pid = wait(NULL);
	}

}



int ampersandchecker(char* arr[]){
	int i = 0;
	while (arr[i] != NULL){
		if (strcmp(arr[i], "&") == 0){
			return 1;
		}
	i++;
	}
}


int main( int argc, char **argv ){
	char *buffer;
	size_t buffer_size = 128;
	ssize_t read;
	char error_message[30] = "An error has occurred\n";
	//allocating memory to the buffer
	buffer = (char *)malloc(buffer_size * sizeof(char));


	//if there are no arguments -- running in interactive mode
	if ( argc == 1 ) {


		printf("wish> ");
		getline( &buffer, &buffer_size, stdin);


		//strip buffer of the newline char
		if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}
		//while they are not the same
		while( strcmp( buffer, "exit") != 0 ){
			char * buffer_copy;
			strcpy(buffer_copy, buffer);
			//creating a temp array to hold values that the user will enter
			char *temp_array[10] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,NULL, NULL};

			//split user cmd by spaces
			char *split_cmd = strtok(buffer, " ");

//			printf("all that i typed: %s\n", buffer_copy);

			int i = 0;
			int count_args = 0;

			while(split_cmd != NULL){
				temp_array[i] = split_cmd;
				i++;
				split_cmd = strtok(NULL, " ");
				count_args++;
			}

//---beginning of latest comment

			//creating address variables for the possible addresses
			char * address_one = "/usr/bin/";
			char * address_two = "/bin/";


			//allocate space in memory for paths
			char *path_one = malloc( strlen(address_one) + strlen(temp_array[0]) + 1 );
			char *path_two = malloc( strlen(address_two) + strlen(temp_array[0]) + 1 );
			

			//create full path for path one
			strcat( path_one, address_one );
			strcat( path_one, temp_array[0] );


			//create full path for path two
			strcat (path_two, address_two );
			strcat (path_two, temp_array[0] );

			//for parallel commands only
			if (ampersandchecker(temp_array) == 1){
				//split at &
				char *and_array[10] = {NULL};
				printf("buffer: %s", buffer_copy);
				//char * buffer_copy_copy = buffer_copy;
				char *split_and = strtok(buffer_copy, "&");

				int count_ands = 0;
				int i = 0;
				while(split_and != NULL){
					and_array[i] = split_and;
//					printf ("and array val %s\n", and_array[i]);
					i++;
					count_ands++;
					split_and = strtok(NULL, "&");

				}

				//create threads and pass values to them
				pthread_t id1; 
				int t1;
				pthread_t id2; 
				int t2;
				pthread_t id3; 
				int t3;
				pthread_t id4; 
				int t4;
				pthread_t id5; 
				int t5;
				if (count_ands == 1){
					t1 = pthread_create( &id1, NULL, first_thread, and_array[0]);
					pthread_join(id1,NULL);
				}
				else if(count_ands == 2){
					t1 = pthread_create( &id1, NULL, first_thread, and_array[0]);
					t2 = pthread_create( &id2, NULL, second_thread, and_array[1]);
					pthread_join(id1,NULL);
					pthread_join(id2,NULL);
				}
				else if(count_ands == 3){
					t1 = pthread_create( &id1, NULL, first_thread, and_array[0]);
					t2 = pthread_create( &id2, NULL, second_thread, and_array[1]);
					t3 = pthread_create( &id3, NULL, third_thread, and_array[2]);
					pthread_join(id1,NULL);
					pthread_join(id2,NULL);
					pthread_join(id3,NULL);
				}
				else if(count_ands == 4){
					t1 = pthread_create( &id1, NULL, first_thread, and_array[0]);
					t2 = pthread_create( &id2, NULL, second_thread, and_array[1]);
					t3 = pthread_create( &id3, NULL, third_thread, and_array[2]);
					t4 = pthread_create( &id4, NULL, fourth_thread, and_array[3]);
					pthread_join(id1,NULL);
					pthread_join(id2,NULL);
					pthread_join(id3,NULL);
					pthread_join(id4,NULL);
		} 
				else if(count_ands == 5){
					t1 = pthread_create( &id1, NULL, first_thread, and_array[0]);
					t2 = pthread_create( &id2, NULL, second_thread, and_array[1]);
					t3 = pthread_create( &id3, NULL, third_thread, and_array[2]);
					t4 = pthread_create( &id4, NULL, fourth_thread, and_array[3]);
					t5 = pthread_create( &id5, NULL, fifth_thread, and_array[4]);		
					pthread_join(id1,NULL);
					pthread_join(id2,NULL);
					pthread_join(id3,NULL);
					pthread_join(id4,NULL);
					pthread_join(id5,NULL);

		}


			}//end of while loop for 

			//execute each of the commands 
			//if cmd if exit, cd or path, > or &
			if(  strcmp(temp_array[0], "cd") == 0 || strcmp( temp_array[0], "exit") == 0 ||  strcmp (temp_array[0], "path") == 0 ||
					strcmp(temp_array[count_args - 2], ">") == 0 ){

				//for exit cmd
				if ( (strcmp(temp_array[0], "exit") == 0) && (strcmp( temp_array[1], "" ) == 0) ){
					exit(0);
				}
				else if( (strcmp(temp_array[0], "exit") == 0) && (strcmp( temp_array[1], "" ) != 0)   ){
					perror("No other arguments needed with exit");
					exit(0);
				}

				//for cd cmd
				else if( strcmp(temp_array[0], "cd") == 0 ) {

					chdir( temp_array[1] );
					//error checking for cd --more than two args passed
					if (temp_array[2] != NULL){printf("Too many arguments\n");}

				}
				//for redirection  code cmd

				else if( strcmp(temp_array[count_args-2], ">") == 0 ){

					if ( access( path_two, X_OK) == 0 ){


						//fill param_array
						char* const param_array[10] = {path_two, NULL,NULL,NULL,NULL,NULL,NULL,NULL, NULL, NULL };
						pid_t pid = fork();
						//error  -- fork didn't work


						if ( pid < 0){
						//	printf( "%ld",(long)getpid());
							fprintf(stderr, "\n usrbin folder fork failed\n");
							exit(1);
						}
						else if(pid == 0){
							
							freopen(temp_array[count_args - 1], "w", stdout);
							execv( path_two, param_array);
							//error checking
							printf("since this prints then execv didn't work");
						}
						pid = wait(NULL); 

					}//end of if the access pathtwo  works


					if ( access( path_one, X_OK) == 0 ){


						//fill param_array
						char* const param_array[10] = {path_one, NULL,NULL,NULL,NULL,NULL,NULL,NULL, NULL, NULL };
						pid_t pid = fork();
						//error  -- fork didn't work


						if ( pid < 0){
						//	printf( "%ld",(long)getpid());
							fprintf(stderr, "\n usrbin folder fork failed\n");
							exit(1);
						}
						else if(pid == 0){
							
							freopen(temp_array[count_args - 1], "w", stdout);
							execv( path_one, param_array);
							//error checking
							printf("since this prints then execv didn't work");
						}
						pid = wait(NULL); 

					}//end of if the access path one works



				}//end of redirection code
				else{
					printf("either path needs to run or something broke");
				}

			}//end of if for special cmds


			//else do this...
			else{
				//check if we can access the path
//				printf("ruunning other none special cmds\n");
				if ( access( path_one, X_OK) == 0 ){


					//fill param_array
					char* const param_array[10] = {path_one, temp_array[1], temp_array[2], temp_array[3], 
							temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work


					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n usrbin folder fork failed\n");
						exit(1);
					}
					else if(pid == 0){


						execv( path_one, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL); 
				}
				else if (access (path_two, X_OK) == 0){


						//fill param_array
					char* const param_array[10] = {path_two, temp_array[1], temp_array[2], temp_array[3], 
						temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work
					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n bin folder-fork failed\n");
						exit(1);
					}
					else if(pid == 0){


						execv( path_two, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL);


				}


				else{
					//error message here
					printf("problem oh\n");
					write(STDERR_FILENO, error_message, strlen(error_message));
				}


			}//end of else for those that are not cd, path or exit

			//asking for user input again
			printf("wish> ");
			getline (&buffer, &buffer_size, stdin);
			if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}


		}//end of while not exit
		exit(0);


	}
//////////////////////////////else if there is one argument -- running in batch mode


	else if( argc == 2 ){
		FILE *fp;
		fp = fopen( argv[1], "r");
		if( fp == NULL){
			printf("cannot open file\n");
			exit(0);
		}
		else{


			getline( &buffer, &buffer_size,fp );


			//strip buffer of the newline char
			if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}
			//while they are not the same
			while(( read = getline(&buffer, &buffer_size, fp)) != -1 ){
				if (buffer[strlen(buffer) -1 ] == '\n'){buffer[strlen(buffer) - 1] = '\0';}


				//creating a temp array to hold values that the user will enter
				char *temp_array[10] = {NULL};


//				printf("%s" , buffer);
				//split user cmd by spaces
				char *split_cmd = strtok(buffer, " ");


				int i = 0;


				while(split_cmd != NULL){
					temp_array[i] = split_cmd;
					i++;
					split_cmd = strtok(NULL, " ");
				}


				//creating address variables for the possible addresses
				char * address_one = "/usr/bin/";
				char * address_two = "/bin/";


				//allocate space in memory for paths
				char *path_one = malloc( strlen(address_one) + strlen(temp_array[0]) + 1 );
				char *path_two = malloc( strlen(address_two) + strlen(temp_array[0]) + 1 );


				//create full path for path one
				strcat( path_one, address_one );
				strcat( path_one, temp_array[0] );


				//create full path for path two
				strcat (path_two, address_two );
				strcat (path_two, temp_array[0] );

			//if cmd if exit, cd or path..
			if(  strcmp(temp_array[0], "cd") == 0 || strcmp( temp_array[0], "exit") == 0 ||  strcmp (temp_array[0], "path") == 0   ){

				//for exit cmd
				if ( (strcmp(temp_array[0], "exit") == 0) && (strcmp( temp_array[1], "" ) == 0) ){
					exit(0);
				}
				else if( (strcmp(temp_array[0], "exit") == 0) && (strcmp( temp_array[1], "" ) != 0)   ){
					perror("No other arguments need with exit");
					exit(0);
				}

				//for cd cmd
				else if( strcmp(temp_array[0], "cd") == 0 ) {

					chdir( temp_array[1] );
					//error checking for cd --more than two args passed
					if (temp_array[2] != NULL){printf("Too many arguments\n");}

				}
				//for path cmd

				else if( strcmp( temp_array[0], "path") == 0  ){
	//stopped here
						}

				else{
					printf("either path needs to run or something broke");
				}

			}

				else{
				//check if we can access the path
				if ( access( path_one, X_OK) == 0 ){


					//fill param_array
					char* const param_array[10] = {path_one, temp_array[1], temp_array[2], temp_array[3], 
							temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work
					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n usrbin folder fork failed\n");
						exit(1);
					}
					else if(pid == 0){


						execv( path_one, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL); 
				}
				else if (access (path_two, X_OK) == 0){


						//fill param_array
					char* const param_array[10] = {path_two, temp_array[1], temp_array[2], temp_array[3], 
						temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9] };
					pid_t pid = fork();
					//error  -- fork didn't work
					if ( pid < 0){
					//	printf( "%ld",(long)getpid());
						fprintf(stderr, "\n bin folder-fork failed\n");
						exit(1);
					}
					else if(pid == 0){


						execv( path_two, param_array);
						//error checking
						printf("since this prints then execv didn't work");
					}
					pid = wait(NULL);


				}


				else{
					printf("command does not exist or file name does not exist\n");
				}
			}
			}//end of else for cd, exit, path
			exit(0);

	}//if the file exists

	}//end of else if for batch file

	//else  --  flag an error
	else{
		perror ("Too many arguments");
		exit(0);
	}


	return 0;
}


