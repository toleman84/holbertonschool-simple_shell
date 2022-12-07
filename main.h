#ifndef _MAIN_H_
#define _MAIN_H_

	/* libraries */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


	/* prototypes */

int lsh_num_builtins(void);
int lsh_launch(char **args);
int lsh_execute(char **args);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
void lsh_loop(void);
int main(int argc, char **argv);
int _strcmp(char *s1, char *s2);

	/* functions declarations for built-in shell commands */

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);


#endif
