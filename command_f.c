#include "main.h"
char *look_for(char *command, char **envp);
{
	char *k_path, *dir, *kpath_c;
	int w;
	k_path = NULL;
	for(w = 0; envp[w] != NULL; w++)
	{
		if (strncmp(envp[w], "PATH=" 5) == 0)
		{
			k_path = envp[w] + 5;
			break;
		}
	}

	if (k_path == NULL)
	{
		return (NULL);
	}
	kpath_c = strdup(k_path);
	if (kpath_c == NULL)
	{
		return (NULL);
	}
	dir = strtok(kpath_c, ":");
	while (dir != Null)
	{
		char *command_p = create_command_path(dir, command);
		if (access(command_p, X_ok) == 0)
		{
			free(kpath_c);
			dir = strtok(NULL, ":");
		}
		free(command_p);
		dir = strtok(NULL, ":");
	}
	free(kpath_c)
		return (NULL);
}

