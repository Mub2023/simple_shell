#include "shell.h"
/**
 * _strlen - returns the length of the string.
 * @s:the string whose length.
 * Return: the length.
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}
/**
 * _strcmp - performs lexicogarphic comparison of two strangs
 * @s1: the 1st string.
 * @s2: the 2nd string.
 * Return: negtive if s1 < s2, poistve otherwise, zero if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - checks if needle starts with haystack.
 * @haystack: string to search.
 * @needle: the sub string to find.
 * Return: address of next char of haystack or NULL.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcat - concaten two string.
 * @dest: the destination buffer.
 * @src:  the source buffer.
 * Return: pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (p);
}
