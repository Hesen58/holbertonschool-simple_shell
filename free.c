#include "main.h"

/**
 * free_arr - freeing array.
 * @arr: array for free.
 */

void free_arr(char **arr)
{
	int j = 0;

	while (arr[j])
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}
