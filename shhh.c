#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>

int main()

{

char *path, *argv[20], buf[80], n, *p;

int m, status, inword, continu;



while(1) {



inword = 0;

p = buf;

m = 0;

continu=0;



printf( "\nshhh> ");

while ( ( n = getchar() ) != '\n'  || continu ) {

	if ( n ==  ' ' ) { 

	    if ( inword ) {

		inword = 0;

		*p++ = 0;

	    } 

	}

	else if ( n == '\n' ) continu = 0;

	else if ( n == '\\' && !inword ) continu = 1;

	else {

	    if ( !inword ) {

		 inword = 1;

		 argv[m++] = p;

		 *p++ = n;

	     }

	     else 

		 *p++ = n;

	}

}	

*p++ = 0;

argv[m] = 0;
/*
Student code below. No need to touch above. 
*/ 

// array for all the linux commands/function arguments given
int commands[20];
// iterator for for-loop. Used for traversing commands array. 
int i = 0; 

// counter for total number of pipes
int pipes = 0; 
// Arrays for filenames
char inputName[50];
char outputName[50]; 
// functionally a boolean flag for whether there is an input redirect or not
int inputRedirect = 0; 
// functionally a boolean flag for whether there is an output redirect or not
int outputRedirect = 0;

// commands[0] should always equal 0. 
commands[0] = 0; 



// we have to do some housekeeping before we can run the commands. 

// check each element in argv[], from 0 to argc (m variable given). 
for (i; i < m; i++) {

	// check if argument is a pipe
	// string compare argument i with the string "|" (pipe symbol)
	// if the strings are equal: 
	if (strcmp(argv[i], "|") == 0) {
		// must do this to save the commands after the pipe
		commands[pipes + 1] = i + 1; 
		// increment pipe count 
		pipes++; 
		// replace the | with a 0. 
		argv[i] = 0; 
	}
	// check if argument is an input redirect.
	else if (strcmp(argv[i], "<") == 0) {
		// copy argument into fileName array. 
		strcpy(inputName, argv[i + 1]); 
		// flip the boolean input redirect flag
		inputRedirect = 1; 
		// replace < with a 0. 
		argv[i] = 0; 
	}
	// check if argument is an output redirect. 
	else if (strcmp(argv[i], ">") == 0) {
		// copy argument into fileName array. 
		strcpy(outputName, argv[i + 1]); 
		// flip the boolean output redirect flag
		outputRedirect = 1; 
		// replace > with a 0.
		argv[i] = 0; 
	}
	
}

// declare left and right side fds
int l_fd[2]; 
int r_fd[2]; 

// now we can do the actual processing of commands. 

// create an interator for the upcoming for loop. 
int j = 0; 
// for (the number of pipes) 
// <= because we have one more process than # of pipes. 
for (j; j <= pipes; j++) {

	// if right pipes need to be created
	if (pipes != 0 && j != pipes) {
		pipe(r_fd);
	}
	pid_t pid = fork(); 

	// check for fork error 
	if (pid < 0) {
		printf("Error with the fork."); 
		return 1; 
	}
	else if (pid > 0) {
		// parent process
		// gotta pipe things correctly

		// if the first process doesn't have a left pipe
		if (j > 0) {
			close(l_fd[0]); 
			close(l_fd[1]); 
		}
		
		l_fd[0] = r_fd[0]; 
		l_fd[1] = r_fd[1]; 
	}
	else {
		// child process
		// gotta run commands

		// input redirection
		// j must = 0 because input redirection can 
		// only occur as first command. 
		if (inputRedirect == 1 && j == 0){
			// handle input redirection
			// because we're effectively outputting a file into 
			// the process, we want to replace stdin with the write
			// end of the left pipe. "Write" "in" to the process. 

			// open file, store in write side of left pipe
			l_fd[1] = open(inputName, O_RDONLY, 0644);
			// close stdin
			close(0); 
			// replace stdin with write end of left pipe
			dup(l_fd[1]);
			// close copy write end of left pipe
			close(l_fd[1]);  
		}
		// pipe handling
		if (pipes > 0) {
			// if first pipe, none to the left
			if (j == 0) {
				// because we are outputting into the pipe, 
				// we want to write into the pipe.
				// so replace stdout with write end of right pipe.

				// close stdout
				close(1); 
				// copy write end of right pipe into stdout's place
				dup(r_fd[1]);
				// close read end of right pipe. Not used.
				close(r_fd[0]); 
				// close original write side of array (non-stdout)
				close(r_fd[1]); 
			}
			// last pipe, no more to the right
			else if (j == pipes) {
				// because we are inputting, we want to read out of the pipe. 
				// so replace stdin with read end of left pipe. 

				// close stdin
				close(0); 
				// copy read end of left pipe into stdin
				dup(l_fd[0]); 
				close(l_fd[0]); 
				close(l_fd[1]); 
			} 
			// middle pipe, pipes to left and right
			else {
				// because we are outputting, we want to write into the pipe.
				// so replace stdout with write end of right pipe. 

				// close stdout
				close(1); 
				// copy write end of right pipe in stdout's place. 
				dup(r_fd[1]); 
				// close read end of right side pipe. not used. 
				close(r_fd[0]);
				// close the original (non-stdout) end of right pipe. 
				close(r_fd[1]); 
				
				// because we are (also) inputting, we want to read out of the pipe. 
				// so replace stdin with read end of left pipe. 
				// close stdin
				close(0); 
				// copy read end of left pipe into stdin's place
				dup(l_fd[0]);
				// close the write end of left pipe. not used.
				close(l_fd[1]); 
				// close the original (non-stdin) end of left
				// side pipe
				close(l_fd[0]); 
			}
		}
		// output redirection
		if (outputRedirect == 1 && j == pipes) {
			// handle output redirection
			// because we're effectively inputting into a file, 
			// we want to replace stdout with the read end of the
			// right pipe. We want to "read" "out" to the file. 

			// copy file into read end of right pipe
			r_fd[0] = open(outputName, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			// close stdout
			close(1); 
			// replace stdout with read end of right pipe
			dup(r_fd[0]); 
			// close copy of read end of right pipe
			close(r_fd[0]); 
		}

		// run the command 
		execvp(argv[commands[j]], argv); 
	}
}



if ( strcmp(argv[0],"exit") == 0 ) exit (0);


wait(&status);

}

return 0; 
}

