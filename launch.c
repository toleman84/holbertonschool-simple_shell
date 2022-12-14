#include "main.h"

/**
 * lsh_launch - launch a program an wait for it terminate.
 * @argv: null terminated list of arguments.
 *
 * Return: Always 1, to continue execution.
 */

int lsh_launch(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
			/* child process */
			actual_command = get_location(command);

			if (execve(actual_command, argv, environ) == -1)
				perror(" -1 ");

			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* error forking */
		perror(" < 0 ");
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

