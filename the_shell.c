#include "shell.c"
/**
 * main - entry point
 * @ac: void parameter
 * @av:  void parameter
 * @env: the environment variable
 * Return: 0 for success.
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{

	char *f = NULL;
	size_t lib = 0;
	ssize_t l_s;
	char *args[100];
	int i;
	(void)av;

	while (1)
	{
		printf("#alxmademe$ ");
		l_s = getline(&f, &lib, stdin);
		if (l_s  == -1)
		{
		perror("Error failed to read input.\n");
		exit(1);
		}
		if (l_s == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		i = 0;
		args[i] = strtok(f, " \n");
		while (args[i] != NULL && i < 99)
		{
			i++;
			args[i] = strtok(NULL, " \n");
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
			break;

		exec_c(args, env);
		free(f);
		f = NULL;
		return (0);
}
