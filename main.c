#include "main.h"
/**
 * main - Simple shell.
 *
 * Return: Success.
 */

int main(void)
{
	int status = 0;
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
		arr = cut_string(buf);
		if (arr == NULL)
		{
			free(buf);
			continue;
		}
	
		if (getenv("PATH") == NULL && arr[0][0] != '.' && arr[0][0] != '/')
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
			free_arr(arr);
			free(buf);
                        exit(127);
		}
		id = fork();
		if (id == 0)
		{
				free(buf);
				execvp(arr[0], arr);
				fprintf(stderr, "./hsh: 1: %s: not found\n", arr[0]);
                        	free_arr(arr);
				exit(127);
		}
		else
		{
			            waitpid(id, &status, 0);

            		if (WIFEXITED(status))
                		status = WEXITSTATUS(status);
           	 	else
                		status = 1;
		}
		free_arr(arr);
		free(buf);
	}
	return (status);
}
