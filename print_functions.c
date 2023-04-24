#include "shell.h"

/**
* print_s - prints a string of characters to the standard output
* @s: string to be printed
*
* Return: number of characters printed
*/
int print_s(char *s)
{
	int n = 0;

	while (s[n] != '\0')
	{
		_putchar(s[n]);
		n++;
	}

	return (n);
}

/**
* _putchar - prints the character c to standard output 
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned and errno set appropriately
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
