#include "main.h"

/**
 * main - Short description.
 * @ac: fisrt member.
 * @argv: second member.
 *
 * Return: Always 0 (success)
 */

int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL, *token;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \t\r\n\a";
	int num_tokens = 0, i;
	(void)ac;
	while (1) /* create a loop for the shell's prompt */
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell ...\n");
			return (1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("Eshell: memory allocation error");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
			num_tokens++, token = strtok(NULL, delim);
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL, execmd(argv);
	}
	free(lineptr_copy);
	free(lineptr);
	return (0);
}

