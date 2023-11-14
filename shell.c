#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Start of the program
 *
 * Return: Always 0
 */

int main(void)
{
	char command[100];

	while (1)
	{
		write(STDOUT_FILENO, "Simple_Shell>", sizeof("Simple_Shell>") - 1);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			write(STDOUT_FILENO, "Exiting Shell..\n", sizeof("Exiting Shell..\n") - 1);
			break;
		}

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Error");
			exit(1);
		}

		if (pid == 0)
		{
			char *args[] = {command, NULL};

			execve(command, args, NULL);
			exit(1);
		}

		else
		{
			int status;

			waitpid(pid, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			{
				write(STDERR_FILENO, "Not recognized\n", sizeof("Not recognized\n") - 1);
			}}}
	return (0);
}
