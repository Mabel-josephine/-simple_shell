#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


 int main(void)
 {
         char command[100];
         pid_t pid;
while (1)
 {
write(STDOUT_FILENO, "please enter a command:",
sizeof("Please enter a command:") -1);
 fflush(stdout);
   /*Handle Ctrl+D (end of file)*/

if (fgets(command, sizeof(command),stdin) == NULL)
 {
write(STDOUT_FILENO, "\nExiting Simple Shell...\n",
sizeof("\nExiting Simple Shell...\n") -1);
break;
}

   /*Remove the newline character from the end of the command*/

 pid = fork();

 if (pid == -1)
{

/*execute the command in the child process*/




perror("Unable to start new process"); exit(1);
 }

 }

 int main(void){
	 char command[] = "/bin/ls";

	 /*command to execute*/
	 executeCommand(command);

	 return 0;
 }








