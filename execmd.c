#include "main.h"

/**
 * execmd - 
 * @argv:
 *
 */

void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		/* get the commad */
		command = argv[0];

		/* execute the comand with execve */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}

