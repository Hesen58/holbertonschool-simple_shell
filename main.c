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

		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		if (getline(&hay, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
					printf("\n");
			free(hay);
			break;
		}
		arr = cut_string(hay, arr);
		id = fork();

		if (id == 0)
		{
			free(hay);
			if (execve(arr[0], arr, environ) == -1)
			{
				free_arr(arr);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		free(hay);
		free_arr(arr);
	}
	return (0);
}
