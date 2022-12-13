#ifndef _MAIN_H_
#define _MAIN_H_


	/* libraries */

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


	/* prototypes */

int lsh_num_builtins(void);
int lsh_launch(char **argv);
int lsh_execute(char **argv);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
void lsh_loop(void);
int main(int argc, char **argv);
int _strcmp(char *s1, char *s2);
int lsh_aliases(void);

char *get_location(char *command);


	/* functions declarations for built-in shell commands */

int lsh_cd(char **argv);
int lsh_help(char **argv);
int lsh_exit(char **argv);


	/* Own functions */

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
unsigned int _strlen(char *s);


	/* environ */

extern char **environ;

#endif
