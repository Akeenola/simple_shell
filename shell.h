#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handles build ins */
int check(char **cmd, char *buf);
void prompt(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *check_path(char **path, char *cmd);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void _exit(char **cmd, char *line);

void print_env(void);
int print_s(char *s);

int _putchar(char c);
/* string functions */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdupl(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void _free(char **buf);

struct builtin
{
	char *env;
	char *exit;
}
builtin;

struct info
{
	int final_exit;
	int ln_count;
}
info;

struct flags
{
	bool interactive;
}
flags;

#endif
