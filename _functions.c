#include "main.h"

/**
 * _strcpy - Copies a string to another string.
 * @dest: pointer to copyed string.
 * @src: pointer to string to copy.
 *
 * Return: Pointer to copied string.
 */

char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (aux);
}

/**
 * _strdup - Pointer to a new allocatd space in memory.
 * @str: string to duplicate.
 *
 * Return: pointer to duplicate string in allocated memory.
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i = 0, len = 0;

	/* validate str input */
	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	/* add null terminator to length */
	len++;

	/* allocate memory */
	duplicate_str = malloc(sizeof(char) * len);

	if (duplicate_str == NULL)
		return (NULL);

	while (i < len)
	{
		*(duplicate_str + i) = *(str + i);
		i++;
	}

	return (duplicate_str);
}

/**
 * _strcat - function that concatenates two strings.
 * @dest: input string.
 * @src: input string.
 *
 * Return: Pointer to the resulting string.
 */

char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';

	while (*src)
		*dest++ = *src++;

	return (temp);
}

/**
 * _strlen - Function that finds the length of the string.
 * @s: input string.
 *
 * Return: Length of the string.
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

