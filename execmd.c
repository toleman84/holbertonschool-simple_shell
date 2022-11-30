#include "main.h"

/**
 * execmd - Short description
 * @argv: first member.
 *
 */

void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		/* get the commad */
		command = argv[0];

		/* generate the path to this command before passing it to execve */
		actual_command = get_location(command);

		/* execute the actual command with execve */
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}

