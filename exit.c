#include "shell.h"
/**
 * *_strncpy - copies a string
 * @dest: the destination string to copied to.
 * @src: the source string.
 * @n: te amount of char to be copied
 * Return: the concatened string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x = 0, y;
	char *s = dest;

	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		y = x;
		while (y < n)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (s);
}
/**
 * *_strncat - concatenates two string.
 * @dest: the first srting.
 * @src: the second string.
 * @n: the amount of bytes to used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x = 0, y = 0;
	char *s = dest;

	while (dest[x] != '\0')
		x++;
	while (src[y] != '\0' && y < n)
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	if (y < n)
		dest[x] = '\0';
	return (s);
}
/**
 * *_strchr - locates a character in a string
 * @s: the string to be parsed.
 * @c: the char to look for.
 * Return: (s)
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
