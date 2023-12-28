#include "main.h"

/**
 * handle_exit_command - handle exit.
 * @arr: array of commands.
 *
 * Return: Status code.
 */
void handle_exit_command(char **arr)
{
	if (access(arr[0], F_OK) == -1 && strcmp(arr[0], "exit") != 0)
	{
		free_arr(arr);
		exit(2);
	}
	if (strcmp(arr[0], "exit") == 0)
	{
		free_arr(arr);
		exit(0);
	}
}
