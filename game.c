/**
 * NWEN 241 Programming Assignment 4
 * game.c C Source File
 *
 * Name:
 * Student ID:
 * 
 * IMPORTANT: You are to complete Tasks 1, 3 and 4 here
 */

#include "common.h"
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1
#define FALE 0


/*====== Fork Only Implementation Start ======*/
/**
 * Fork Only Implementation Block
 * Write all code related to the fork only implementation within this block
 */ 

#if defined(FORK_IMPL)

int main(void)
{
    int userInput = 0;	 
    pid_t pid = 0;
	 
	 //make sure input is either 1, 2, or 3
    while(TRUE){
    	// FIXME: Implement Task 3 here
    printf(" *** GAME MENU: ***\n (1) Guessing Game \n (2) Tic-Tac-Toe \n (3) Exit \n");
        
        int result = scanf("%c", &userInput);		
		
		if(userInput == '3'){
			exit(0);
			}		 
		
		else if(userInput == '1'){
		/*FORK CHILD PROCESS*/		 
		 pid = fork();
			 if(pid < 0){
				fprintf(stderr, "Fork Failed");
				return 1;		 
			 }   
			 else if(pid == 0){
				/*child process*/
				execlp("/bin/ls","ls", NULL);
		 	}
		 	else{
				/*parent waits for child to complete*/
				waitpid(pid, NULL, 0);
				printf("Child Complete \n");	 	
		 	}
		}
		
		else if(userInput == '2'){
		/*FORK CHILD PROCESS*/		 
		 pid = fork();
		 
			 if(pid < 0){
				fprintf(stderr, "Fork Failed");
				return 1;		 
			 }   
			 else if(pid == 0){
				/*child process*/
						 
		 	}
		 	else {
					/*parent waits for child to complete*/
					waitpid(pid, NULL, 0);
					printf("Child Complete  \n");	 	
			 	}
 	 }
		else{
			scanf("%c", &userInput);
			printf("\n Please enter 1, 2, or 3 depending on the "); 
			printf("action \n you'd like to perform.\n");
		}	
   } 
 }
 


/*====== Fork Only Implementation End ======*/





/*====== Fork + Exec Implementation Start ======*/
/**
 * Fork + Exec Implementation Block
 * Write all code related to the fork + exec implementation within this block
 */ 

#elif defined(FORK_EXEC_IMPL)

int main(void)
{
    // FIXME: Implement Task 4 here
    return 0;
}

/*====== Fork + Exec Implementation End ======*/




#else

/*====== No Implementation Start ======*/
/**
 * No Implementation Block
 * Do not write anything in this block
 */ 
#error "Did not specify implementation to compile."

#endif

/*====== No Implementation End ======*/

