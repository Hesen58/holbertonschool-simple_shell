#include "main.h"

/**
 * execute_command - handle the executing command.
 * @arr: array of commands.
 *
 * Return: status code.
 */
int execute_command(char **arr)
{
	int status = 0;
	pid_t id = fork();

	if (arr[0] != NULL && strcmp(arr[0], "exit") == 0)
	{
		status = (arr[1] != NULL) ? 2 : 0;
		free_arr(arr);
		exit(status);
	}

	if (id == 0)
	{
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

	return (status);
}
