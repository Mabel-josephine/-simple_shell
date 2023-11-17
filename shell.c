#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

/**
 * executeCommand - Executes the command
 *
 * Return: Always 0
 */

void executeCommand(char *command)

{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error starting chiild process");
		exit(1);
	}

	if (pid == 0)
	{
		char *args[2];
		args[0]	= command;
		args[1] = NULL;

		char **memArgs = malloc(sizeof(char *) * 2);
		if (memArgs == NULL) {
			perror("Memory allocation error");
			exit(1);
		}

		memArgs[0] = strdup(command);
		memArgs[1] = NULL;

		execvp(memArgs[0], memArgs);
		perror("Error executing command");
		free(memArgs[0]);
		free(memArgs);
		exit(1);
	}

	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			write(STDERR_FILENO, "Unrecognized Command\n",
					sizeof("Unrecognized Command\n") - 1);
		}
	}

}

