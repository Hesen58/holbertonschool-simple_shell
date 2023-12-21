#include "main.h"
/**
 * cut_string - Create new array with strtok
 * @hay: user input.
 * @arr: array.
 *
 * Return: 2d array.
 */

char **cut_string(char *hay, char **arr)
{
	char *tok;
	int i = 0;

	tok = strtok(hay, " \n");

	arr = (char **)malloc(sizeof(char *) * 250);

	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);

		tok = strtok(NULL, " \n");
		i++;
	}

	return (arr);
}
