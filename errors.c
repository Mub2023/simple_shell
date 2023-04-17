#include "shell.h"
/**
 * _eputs - prints an input string
 * @str: the string pointer
 * Return: nothing
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;

	while (str[x] != '\0')
	{
		_eputchar(str[x]);
			x++;
	}
}
/**
 * _eputchar - writes the char c to stderr
 * @c: the character to print
 * Return: 1 Sccess or -1 if error ouccred
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
/**
 * _putfd - writes the character c to given fd
 * @c: the character to print
 * @fd: the filedescritor to write
 * Return: 1 on Success or -1 on error
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}
/**
 * _putsfd - prints an input string.
 * @str: the string to printed.
 * @fd: the filedescritor to write
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}
