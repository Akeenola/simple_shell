#include "shell.h"
/**
* main - reads instructions with args, execute then print output loop
* @argc: argument count
* @argv: argument vector
* @env: environment vector
*
* Return: 0
*/

int main(int argc, char **argv, char *env[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t buf = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)env, (void)argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		free_buffers(command);
		free_buffers(paths);
		free(pathcommand);
		prompt_user();
		linesize = getline(&line, &buf, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = tokenizer(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (checker(command, line))
			continue;
		path = find_path();
		paths = tokenizer(path);
		pathcommand = test_path(paths, command[0]);
		if (!pathcommand)
			perror(argv[0]);
		else
			execution(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
