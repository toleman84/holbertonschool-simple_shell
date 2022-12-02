#include "main.h"

/**
 * main - Short description.
 * @ac: first member.
 * @argv: second member.
 *
 * Return: Always
 */

int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	int i;
	char *token;

	(void)ac; /* declaring void variables */
	while (1) /* create a infinite loopt of prompt */
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1) /* check if the getline function failed or reached EOF or user use CTRL+D */
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		lineptr_copy = malloc(sizeof(char) * nchars_read); /* allocate space for a copy of the lineptr */
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		_strcpy(lineptr_copy, lineptr); /*copy lineptr - lineptr_copy*/

		/*** split the string (lineptr) into an array of words ***/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim);

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens); /* allocate space to hold the array of strings */
		token = strtok(lineptr_copy, delim); /* store token in the argv array */

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			_strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv); /* execute the command */
	}
	free(lineptr_copy); /* free up allocated memory */
	free(lineptr);

	return (0);
}

