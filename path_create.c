<<<<<<< HEAD
#include "shell.h"
=======
#include "main.h"

/**
 *
 * creating command path
 *
 * Return: ...
 */

>>>>>>> 5caa697e48cc78abf34c473776a5d49ea56425bf
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
