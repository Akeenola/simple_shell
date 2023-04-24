#include "shell.h"

/**
* _exit - handles the exit command
* @cmd: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void _exit(char **cmd, char *line)
{
	free(line);
	free_buffers(cmd);
	exit(0);
}
