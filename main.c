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
		char *buf = NULL;
		size_t n = 0;
		struct stat st;
		char **arr;
		pid_t id;

		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
		}

		if (getline(&buf, &n, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
					printf("\n");
			free(buf);
			break;
		}
		arr = cut_string(buf, arr);

		if (arr == NULL || arr[0] == NULL || arr[0][0] == '\0')
		{
			free(buf);
			free_arr(arr);
			continue;
		}
		if (strcmp(arr[0], "exit") == 0)
		{
			free(buf);
			free_arr(arr);
			return (2);
		}

		if (stat(arr[0], &st) == 0)
		{
			id = fork();

			if (id == 0)
			{
				free(buf);
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
		}
		else
			fprintf(stderr, "%s: %d: %s: not found\n", "hsh", 1, arr[0]);
		free(buf);
		free_arr(arr);
	}
	return (0);
}
