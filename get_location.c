#include "main.h"

/**
 * get_location - Short description.
 * @command: first member.
 *
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		/* duplicate the path string */
		path_copy = _strdup(path);
		/* get length of the command */
		command_length = _strlen(command);

		/* break down the path variable and get all the directories */
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			/* get the length of the directory */
			directory_length = _strlen(path_token);
			/* allocate memory the command with the directory */
			file_path = malloc(command_length + directory_length + 2);
			/* NB: we added 2: the slash and null character */

			/* copy the directory path and concat the command */
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			/* if file path exists and return it, otherwise ... */
			if (stat(file_path, &buffer) == 0)
			{
/* return value of 0 means success implying that the file_path is valid*/
/* free up allocated memory before returning your file_path */
				free(path_copy);

				return (file_path);
			}
			else
			{
/* free up the file_path memory so we can check for another path*/
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
/* if we don't get file_path that exists, we return NULL but we need to free */
		free(path_copy);

/* let's see if the command itself is a file_path that exists */
		if (stat(command, &buffer) == 0)
			return (command);

		return (NULL);
	}
	return (NULL);
}

