#include "main.h"

char *env_path(void)
{
	char *path = getenv("PATH");
	char *tok = strtok(path, ":");

	while (tok != NULL)
	{
		if (tok != NULL)
			path = tok;
		tok = strtok(NULL, ":");
	}

	free(tok);
	return (path);
}
