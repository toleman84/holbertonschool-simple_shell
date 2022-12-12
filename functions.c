#include "main.h"

/**
 * _strcmp - function that compares strings
 * @s1: first string.
 * @s2: second string
 *
 * Return: 0.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}

/**
 * _strdup - function that duplicates strings
 * @str: string that doubles
 *
 * Return: duplicate string
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++; /* add null terminator to length */

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
 * _strcpy - funtion that copies
 * @dest: target copy
 * @src: source
 *
 * Return: dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcat - concatenating function
 * @dest: target concat
 * @src: source
 *
 * Return: dest.
 */

char *_strcat(char *dest, char *src)
{
	int j, length = 0;

	while (dest[length] != '\0')
		length++;

	for (j = 0; src[j] != '\0'; j++, length++)
	{
		dest[length] = src[j];
	}
	dest[length] = '\0';

	return (dest);
}

/**
 * _strlen - fuction that enumerates.
 * @s: source.
 *
 * Return: enumerated.
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

