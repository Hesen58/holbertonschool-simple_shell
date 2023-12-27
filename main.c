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
		id = fork();

		if (id == 0)
		{
				free(buf);
				execvp(arr[0], arr);
				fprintf(stderr, "./hsh: 1: %s: Not found\n", arr[0]);
                        	free_arr(arr);
                        	return (127);
		}
		else
		{
			wait(NULL);
		}
		free_arr(arr);
		free(buf);
	}
	return (0);
}
