#include "main.h"
/**
 * main - Simple shell.
 *
 * Return: Success.
 */

int main(void)
{
	while (1)
	{
		char *hay = NULL;
		size_t n = 0;
		char **arr;
		pid_t id;

		if (getline(&hay, &n, stdin) == EOF)
		{
			printf("\n");
			break;
		}
		arr = cut_string(hay, arr);
		id = fork();

		if (id == 0)
		{
			if (execve(arr[0], arr, environ) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
