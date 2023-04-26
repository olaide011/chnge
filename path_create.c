
#include "shell.h"

/**
 * createpath - create command path
 * @dir: directory
 * @command: input
 * Return: created path
 */

char *createpath(char *dir, char *command);
{
	size_t length_dir;
	char *createpath;
	size_t c_length, pth_length;


	length_dir = strlen(dir);
	c_length = strlen(command);
	pth_length = length_dir + c_length + 2;
	createpath = malloc(pth_length);

	if (createpath == NULL)
	{
		return (NULL);
	}

	snprintf(createpath, pth_lenght, "%s/%s", dir, command);
	return (createpath);
}
