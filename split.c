#include "main.h"
/**
 * split_command - Create new array with strtok
 * @input: user input.
 *
 * Return: 2d array.
 */

char **split_command(char *input)
{
	char *tok, **arr;
	int i = 0;
	int k;

	tok = strtok(input, " \n\t");
	if (tok == NULL)
	{
		free(input);
		return (NULL);
	}
	arr = (char **)malloc(sizeof(char *) * 250);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;
	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);
		arr[i][strlen(tok)] = '\0';
		i++;
		tok = strtok(NULL, " \n\t");
	}
	arr[i] = NULL;
	free(input);
	return (arr);
}
