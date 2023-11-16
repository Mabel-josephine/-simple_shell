#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024 /* maximum input size*/

void executeCommand(char *command) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* The child process */
        char *args[] = {command, NULL};
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        /* The parent process */
        wait(NULL);
    }
}

int main(void) {
    char command[] = "/bin/ls";

    /* Execute the command */
    executeCommand(command);

    return 0;
}









