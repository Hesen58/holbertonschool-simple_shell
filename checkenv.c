#include "main.h"

char *env_path(char *buf)
{
	char *path;
	char *token;
	char full_path[100];

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, buf);

		if (access(full_path, X_OK) == 0)
		{
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
