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
	}
	return (0);
}
