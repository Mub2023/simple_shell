#include "shell.h"
/**
 * _strcpy - copy string.
 * @dest: the destination.
 * @src: the source
 * Return: pointer to the destination.
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
	return (dest);
}
/**
 * _strdup - duplicates a string.
 * @str: the string to duplicated string.
 * Return: pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
		int len = 0;
		char *r;

		if (str == NULL)
			return (NULL);
		while (*str++)
			len++;
		r = malloc(sizeof(char) * (len + 1));
		if (!r)
			return (NULL);
		for (len++; len--;)
			r[len] = *--str;
		return (r);
}
/**
 * _puts - prints an input string.
 * @str: the pointer of the string.
 * Return: nothing.
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
	}
}
/**
 * _putchar - write the char c to stdout.
 * @c: the char to print.
 * Return: 1 on success or -1 on error and
 * errno is set appropriaately.
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
