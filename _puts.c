#include "shell.h"
/**
 * _puts - prints a string to standard output
 * @str: pointer to the string
 * Return: void
*/

void _puts(char *str)
{
int n = 0;
while (str[n])
{
	_putchar(str[n]);
	n++;
}
}
