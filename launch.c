#include "main.h"

/**
 * lsh_launch - launch a program an wait for it ti terminate.
 * @args: ull terminated list of arguments (including program)
 *
 * Return: Always 1, to continue execution.
 */

int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* child process */
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("lsh");
	}
	else
	{
		/* parent process */
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

