#include "main.h"

/**
 * __exit - Function to exit the shell
 * @argv: arguments that have been passed (void)
 *
 * Return: 0 if success.
 */

void __exit(char **argv)
{
	(void)argv;
	exit(0);
}

/**
 * _cd - function to change directory.
 * @argv: arguments that have been passed (void)
 *
 */

void _cd(char **argv)
{
	(void)argv;
	if (argv[1] == NULL)
	{
		fprintf(stderr, "Eshell: cd: missing argument \"cd\"\n");
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("Error");
		}
	}
}

/**
 * _help - help query function.
 * @argv: arguments that have been passed (void)
 *
 */

void _help(char **argv)
{
	char *helptext =
		"Eshell - Economic Shell. \n"
		"the following commands are available:\n"
		"  cd     Change the workind directory.\n"
		"  help   Print this help text.\n"
		"  exit   Exit the Eshell.\n";
	printf("%s", helptext);

	(void)argv;
}

