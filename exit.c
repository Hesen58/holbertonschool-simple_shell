#include "main.h"

/**
 * handle_exit_command - handle exit.
 * @arr: array of commands.
 *
 * Return: Status code.
 */
int handle_exit_command(char **arr)
{
	int status = 0;

	if (arr[0] != NULL && strcmp(arr[0], "exit") == 0)
	{
		if (arr[1] != NULL)
			status = 2;
		free_arr(arr);
		exit(status);
	}

	return (status);
}
