#ifndef _MAIN_H_
#define _MAIN_H_


/* libraries */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <sys/wait.h>

/* prototypes */

int main(int ac, char **argv);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void execmd(char **argv);
char *get_location(char *command);


/* Our functions */

char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
int _strlen(const char *s);

/* exit func */

int exit_func(char **args);


#endif
