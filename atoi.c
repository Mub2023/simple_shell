#include "shell.h"
/**
 * interactive - return ture if shell is interactive mode.
 * @info: struct address
 * Return: 1 if interactive or 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks if character is delimeter.
 * @c: the char to check.
 * @delim: the delimeter string.
 * Return: 1 if ture , 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - checks for alphabetic.
 * @c: the char to input.
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts a string to int.
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int x, si = 1, f = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && f != 2; x++)
	{
		if (s[x] == '-')
			si *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
		f = 1;
		result *= 10;
		result += (s[x] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (si == -1)
		output = result;
	else
		output = result;

	return (output);
}
