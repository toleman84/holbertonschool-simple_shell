#include "main.h"

/**
 * lsh_read_line - read line of input from stdin
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
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS); /* we received an EOF */
		}
		else
		{
			perror("lsh: getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
#else
#define LSH_RL_BUFSIZE 1024
	int bufsize = LSH_RL_BUFSIZE, position = 0, c;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		/* read a character */
		c = getchar();

		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;

		position++;

		/* if we have exceeded the buffer, reallocate */
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
#endif
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

/**
 *
 *
 *
 */

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char*));

			if (!tokens)
			{
				free(tokens_backup);
			fprintf(stderr, "lsh: allocation error\n");
			exit(EXIT_FAILURE);
			}
		}
	
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

