#include "main.h"

/**
 * lsh_read_line - read line of input from stdin.
 *
 * Return: the line from stdin.
 */

char *lsh_read_line(void)
{
#ifdef LSH_USE_STD_GETLINE
	char *line = NULL;
	ssize_t bufsize = 0; /* have getline allocate a buffer for us */

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (fstat(stdin)) /* we received an EOF */
			exit(EXIT_SUCCESS);
		else
		{
			perror("Eshell: getline\n"), exit(EXIT_FAILURE);
		}
	}
	return (line);
#else
#define LSH_RL_BUFSIZE 1024
	int bufsize = LSH_RL_BUFSIZE, position = 0, c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		free(buffer);
		fprintf(stderr, "Eshell: allocation error\n"), exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
			exit(EXIT_SUCCESS);
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
	}
#endif
}
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 * lsh_split_line - Function that split line.
 * @line: Lines to split.
 *
 * Return: tokens
 */

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token; /***tokens_backup*/

	if (!tokens)
	{
		fprintf(stderr, "Eshell: allocation error\n");
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

