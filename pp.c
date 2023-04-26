#include "shell.h"
/**
 * exec_c - function
 * @args: -------
 * @envp: -------
 * Return: ------
 */
void exec_c(char **args, char **envp)
{
	pid_t child_pid;
	int situat;

	char *command_path = find_command(args[0], envp);

	if (command_path == NULL)
	{
		perror(args[0]);
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("child_pid");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(command_path, args, envp) == -1)
		{
			perror("execve");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(child_pid, &situat, WUNTRACED);
		} while (!WIFEXITED(situat) && !WIFSIGNALED(situat));
	}
	free(command_path);
}

