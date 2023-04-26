#include "shell.h"
/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in the string, -1 on error.
 */
int _erratoi(char *s)
{
	int x = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			result *= 10;
			result += (s[x] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}
/**
 * print_error - prints an error message
 * @info: the struct parameter
 * @estr: the string containing speciftied error type
 * Return: 0 if no string , converted number otherwise
 * -1 on error.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
/**
 * print_d - func prints a decimal number
 * @input: the input.
 * @fd: the filedescriptor to write to
 * Return: the number of char printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int x, count = 0;
	unsigned int abs, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		abs = -input;
		__putchar('-');
		count++;
	}
	else
		abs = input;
	current = abs;
	for (x = 1000000000; x > 1; x /= 10)
	{
		if (abs / x)
		{
			__putchar('0' + current / x);
			count++;
		}
		current %= x;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
/**
 * convert_number - converter func, a clone of itoa.
 * @num: integer
 * @base: base integer
 * @flags: argument flags.
 * Return: the string.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buffer[50];
	char si = 0;
	char *p;
	unsigned long x = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		si = '-';
	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = arr[x % base];
		x /= base;
	} while (x != 0);

	if (si)
		*--p = si;
	return (p);
}
/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of string,
 * Return: Always 0 (success)
 */
void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!x || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;
		}
}
