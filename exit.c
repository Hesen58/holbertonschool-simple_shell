#include "main.h"

/**
 * handle_exit_command - handle exit.
 * @arr: array of commands.
 *
 * Return: Status code.
 */
void handle_exit_command(char **arr)
{
	int status = 0;

	if (arr[1])
	{
		status = atoi(arr[1]);
		if (status <= -1)
			status = 2;
		free_arr(arr);
		exit(status);
	}
	free_arr(arr);
	exit(0);
}
