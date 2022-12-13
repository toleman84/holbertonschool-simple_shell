#include "main.h"

/* list of built-in commands, followed by their corresponding functions */

char (*builtin_str[]) = {
	"cd",
	"help",
	"exit",
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit,
};

/**
 * lsh_num_builtins - Short description.
 *
 * Return: Size of
 */

int lsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * lsh_cd - Short desciption
 * @argv: Null terminated list of arguments
 *
 * Return: 1
 */

int lsh_cd(char **argv)
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Eshell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 * lsh_help - Command function help
 * @argv: Null terminated list of arguments
 *
 * Return: 1
 */

int lsh_help(char **argv)
{
	int i;

	(void)argv;

	printf("  Eshell\n");
	printf("  type program names and arguments and hit enter.\n");
	printf("  the following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("     %s\n", builtin_str[i]);
	}
	printf("  use the man command for information on other programs.\n");
	return (1);
}

/**
 * lsh_exit - Command function exit.
 * @argv: Null terminated list of arguments.
 *
 * Return: Always 0 (success)
 */

int lsh_exit(char **argv)
{
	(void)argv;
	exit(0);
}

/**
 * lsh_execute - execute shell built-in or launch program
 * @argv: Null terminated list of arguments.
 *
 * Return: 1 of the shell should continue running, 0 if it should terminated.
 */

int lsh_execute(char **argv)
{
	int i;

	if (argv[0] == NULL)
	{
		/* an empty command was entered */
		return (1);
	}
	for (i = 0; i < lsh_num_builtins(); i++)
	{
		if (_strcmp(argv[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(argv));
	}
	return (lsh_launch(argv));
}

