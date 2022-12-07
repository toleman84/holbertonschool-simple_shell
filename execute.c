#include "main.h"

/* list of built-in commands, followed by their corresponding functions */

char *builtin_str[] = {
        "cd",
        "help",
        "exit"
};

int (*builtin_func[]) (char **) = {
        &lsh_cd,
        &lsh_help,
        &lsh_exit
};

int lsh_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

/**
 *
 *
 */

int lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 *
 *
 */

int lsh_help(char **args)
{
	int i;

	(void)args;

	printf("Shell\n");
	printf("type program names and arguments and hit enter.\n");
	printf("the following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf(" %s\n", builtin_str[i]);
	}
	printf("use the man command for information on other programs.\n");
	return (1);
}

/**
 *
 *
 */

int lsh_exit(char **args)
{
	(void)args;

	return (0);
}

/**
 * lsh_execute - execute shell built-in or launch program
 * @args: Null terminated list of arguments.
 *
 * Return: 1 of the shell should continue running, 0 if it should terminated.
 */

int lsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/* an empty command was entered */
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	}
	return (lsh_launch(args));
}

