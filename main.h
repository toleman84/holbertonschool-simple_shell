#ifndef _MAIN_H_
#define _MAIN_H_

/* libraries */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* prototypes */

int main(int ac, char **argv);
void execmd(char **argv);
char *get_location(char *command);

/* built in functions */

void __exit(char **argv);
void _cd(char **argv);
void _help(char **argv);
int num_builtins(void);

/* our functions */

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
unsigned int _strlen(char *s);

/**
 * struct builtin - Short description
 * @name: first member.
 * @func: second member.
 */

struct builtin
{
	char *name;
	void (*func)(char **argv);
};

#endif
