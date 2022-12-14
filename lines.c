#include "main.h"

/**
 * lsh_read_line - read line of input from stdin.
 *
 * Return: the line from stdin.
 */

char *lsh_read_line(void)
{
	int position = 0, c;
	char *line = NULL, *buffer = NULL;
	size_t bufsize = 0;
	ssize_t nchars_read; /* have getline allocate a buffer for us */

	nchars_read = getline(&line, &bufsize, stdin);
	if (nchars_read == -1)
	{
		free(line); /* valgrind */
		printf("Exiting shell ...\n");
		exit(EXIT_SUCCESS);
	}
	return (line);

/*	int position = 0, c;*/
	buffer = malloc(sizeof(char) * nchars_read);
	if (!buffer)
	{
		free(buffer);
		printf("Eshell: allocation error\n"), exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
			printf("Exiting Eshell ...\n"), exit(EXIT_SUCCESS);
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
	}

}
/*#define LSH_TOK_BUFSIZE 64*/
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * lsh_split_line - Function that split line.
 * @line: Lines to split.
 *
 * Return: tokens
 */

char **lsh_split_line(char *line)
{
	int position = 0;
	char **tokens = malloc(64 * sizeof(char *));
	char *token; /***tokens_backup*/

	if (!tokens)
	{
		printf("Eshell: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

