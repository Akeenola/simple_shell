/**
 * _strlen - finds the length of a given string
 * @s: pointer to string
 * Return: void
*/


int _strlen(const char *s)
{
  int i;
  i	= 	0;
while (s[i])
	i++;

return (i);
}


/**
 * *_strcpy -  copy the string pointed to 
 * @dest: pointer to a  string
 * @src: pointer to a string
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i;
	i	=	1;

	while (src[i] != '\0')
	  {
	    dest[i]	=	src[i];
	    i++;
	  }
	return (dest);
}
