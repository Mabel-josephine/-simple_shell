#include <unistd.h>

/**
* main - Start of the program
* Return: Always 0
*/

int main(void)
{
	const char text[] = "This code truly passes Betty check!\n";
		size_t length = sizeof(text) - 1;

		write(STDOUT_FILENO, text, length);

		return (0);
}
