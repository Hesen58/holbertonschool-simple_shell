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
		/*if (access(arr[0], X_OK) == -1)
                {
                        fprintf(stderr, "%s: %d: %s: not found\n", "./hsh", 1, arr[0]);
                        free(buf);
                        free_arr(arr);
                        return (127);
                }*/

		/*if (access(arr[0], F_OK) == 0)
		{*/
			id = fork();

			if (id == 0)
			{
				free(buf);
				if (execvp(arr[0], arr) == -1)
				{
					free_arr(arr);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);
			}
		/*}*/

		free_arr(arr);
		free(buf);
	}
	return (0);
}
