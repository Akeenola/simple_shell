#include "shell.h"

/**
 * execution - executes the command
 * @cmd: command to run
 * Return: 0 on success1 -1 if cmd is exit and 1 on any other error
 */
int execution(char **cmd)
{

	pid_t child_pid;
	int status;

	if (strncmp("exit", cmd[0], 4) == 0)
		return (-1);

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else
		wait(&status);

	return (0);
}


/**
 * main - main simple shell
 * @ac: number of arguments
 * @av: list of command line arguments
 * Return: Always 0, -1 on error.
 */

int main(int ac, char **av)
{

	int response;
	char **tokens;
	size_t bufsize = BUFSIZ;
	int isPipe = 0;
	char *buffer;

	if (ac >= 2)
	{
		/*TODO: Handle cases where there is no argument, only the command*/
		if (execve(av[1], av, NULL) == -1)
		{
			perror("Error");
			exit(-1);
		}
		return (0);
	}

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Not aable to allocate buffer");
		exit(1);
	}

	do {
		if (isatty(fileno(stdin)))
		{
			isPipe = 1;
			_puts("($)");
		}

		getline(&buffer, &bufsize, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		tokens = stringToTokens(buffer);
		response = execution(tokens);
	} while (isPipe && response != -1);

	return (0);
}
