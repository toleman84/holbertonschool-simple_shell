#include "main.h"

/**
 * get_location - Short description.
 * @command: first member.
 *
 * Return: Always
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path); /* duplicate the path string */
		command_length = _strlen(command); /* length of the command */
		path_token = strtok(path_copy, ":"); /* path and directories */
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			/* allocate memory the command with the directory */
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token); /* copy dir path and concat */
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0) /* if path exists */
			{
/* return value of 0 means success implying that the file_path is valid*/
/* free up allocated memory before returning your file_path */
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path); /* free file_path memory */
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0) /* if the command itself */
			return (command);
		return (NULL);
	}
	return (NULL);
}

