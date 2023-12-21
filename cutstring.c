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
	int i = 0, j = 0;

	tok = strtok(hay, " ");

	arr = (char **)malloc(sizeof(char *) * 250);

	while (tok != NULL)
	{
		j = strlen(tok);
		arr[i] = (char *)malloc(j + 1);
		strcpy(arr[i], tok);
		tok = strtok(NULL, " ");	
		i++;
	}

	return (arr);
}
