#include "main.h"

/**
 * lsh_loop - loop prompt
 *
 */

void lsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("(Eshell) $ ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while (status);
}


/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: status code.
 */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	/* load config files, if any */

	/* run command loop */
	lsh_loop();

	/* perform any shutdown/clean up */
	return (EXIT_SUCCESS);
}

