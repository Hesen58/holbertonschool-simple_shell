#include "main.h"
/**
 * cut_string - Create new array with strtok
 * @hay: user input.
 * @arr: array.
 *
 * Return: 2d array.
 */

char **cut_string(char *buf, char **arr)
{
	char *tok, bin[] = "/bin/", *temp = bin;
	int i = 0;
	int k;

	tok = strtok(buf, " \n");

	arr = (char **)malloc(sizeof(char *) * 250);
	for (k = 0; k < 250; k++)
		arr[k] = NULL;

	while (tok != NULL)
	{
		arr[i] = (char *)malloc(strlen(tok) + 1);
		strcpy(arr[i], tok);

		tok = strtok(NULL, " \n");
		i++;
	}
	if (buf[0] == '\n')
	  return (NULL);
	if (buf != NULL && strncmp(buf, bin, 5) != 0)
	{
		temp = strdup(bin);
		temp = realloc(temp, strlen(arr[0]) + strlen(temp) + 1);
		strcat(temp, arr[0]);
		free(arr[0]);
		arr[0] = temp;
		}
	arr[i] = NULL;

	return (arr);
}
