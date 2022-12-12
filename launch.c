#include "main.h"

/**
 * lsh_launch - launch a program an wait for it terminate.
 * @argv: null terminated list of arguments
 *
 * Return: Always 1, to continue execution.
 */

int lsh_launch(char **argv)
{
	pid_t pid;
	int status;
	char *command = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
			/* child process */
			if (execvp(command, argv) == -1)
				perror("Error: - 1");

			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("Error: < 0");
	}
	else
	{
		/* parent process */
		do
			waitpid(pid, &status, WUNTRACED);

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

