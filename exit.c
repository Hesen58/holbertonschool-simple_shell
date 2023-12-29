#include "main.h"

/**
 * handle_exit_command - handle exit.
 * @arr: array of commands.
 * @exit_flag: exit flag.
 *
 * Return: Status code.
 */
void handle_exit_command(char **arr, int *exit_flag)
{
	if (strcmp(arr[0], "exit") == 0 && arr[1] == NULL)
	{
		free_arr(arr);
		*exit_flag = 1;
	}
}
