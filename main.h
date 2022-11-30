#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **argv);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void execmd(char **argv);
char *get_location(char *command);

#endif
