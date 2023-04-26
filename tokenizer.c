#include "shell.h"

/**
 * *nbr_spaces - return the number of occurent of a string
 * @str: string to check
 * Return: sum on Success
 */

unsigned int nbr_spaces(char *str)
{
	int i, sum;
	sum= 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i]  == ' ')
			sum++;
	}

	return (sum);
}


/**
  *stringToTokens - split a sentence into multiple words.
  *@str: the string passed as argument.  *Return: tokens on success
  */
char **strToTokens(char *str)
{
int i = 0;
const char separator[] = " ";
int spaces = nbr_spaces(str);
char **tokens = malloc(sizeof(char *) * (spaces + 1));
char *token;

if (!tokens)
{
	fprintf(stderr, "sh: allocation error\n");
	exit(1);
}

token = strtok(str, separator);

while (token != NULL)
{
	tokens[i] = token;
	token = strtok(NULL, separator);
	i++;
}
tokens[i] = NULL;

return (tokens);
}
