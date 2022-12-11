#include "main.h"

/**
 * struct builtin - Short description.
 *
 *
 */

struct builtin builtins[] = {
	{"exit", __exit},
	{"cd", _cd},
	{"help", _help},
};

/**
 * num_builtins - Short description.
 *
 * Return: sizeof builtins and struct builtin.
 */

int num_builtins(void)
{
	return (sizeof(builtins) / sizeof(struct builtin));
}

/**
 * execmd - function to execute the commands
 * @argv: arguments that have been passed.
 *
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid;
	int status;
	int i;
	extern char** environ;

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(argv[0], builtins[i].name) == 0)
		{
			builtins[i].func(argv);
			return;
		}
	}

	pid = fork();

	if (pid == 0)
	{
		if (argv)
		{	/* get the command */
			command = argv[0];
			/* generate path to command before to execve */
			actual_command = get_location(command);
			/* execute the actual command with execve */
			if (execve(actual_command, argv, environ))
				perror("Error: -1 ");
		}
	}
	else if (pid < 0)
		perror("Eshell <0 ");
	else
	{
		do{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

}

