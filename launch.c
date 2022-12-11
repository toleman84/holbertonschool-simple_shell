#include "main.h"

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);

		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}

/**
 * lsh_launch - launch a program an wait for it terminate.
 * @args: null terminated list of arguments.
 *
 * Return: Always 1, to continue execution.
 */ 

int lsh_launch(char **argv)
{
	pid_t pid;
	int status;
	char *command = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];
			/* child process */
			if (execvp(command, argv) == -1)
				perror("Eshell - 1");
		
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* error forking */
		perror("Eshell < 0");
	}
	else
	{
		/* parent process */
		do
			waitpid(pid, &status, WUNTRACED);

		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

