#include "shell.h"

/**
* check_path - checks whether path is valid
* @path: tokenized path
* @cmd: user entered command
*
* Return: path appended with command on success
* NULL on failure
*/
char *check_path(char **path, char *cmd)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path(path[i], cmd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
