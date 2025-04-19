#include "shell.h"

/**
* _strlen - returns the length of a string
* @s: the string
* Return: length
*/
int _strlen(const char *s)
{
int len = 0;

while (s[len])
len++;
return (len);
}

/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
* Return: 0 if equal, positive or negative if not
*/
int _strcmp(const char *s1, const char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}

/**
* _strcpy - copies the string from src to dest
* @dest: destination buffer
* @src: source string
* Return: pointer to dest
*/
char *_strcat(char *dest, const char *src)
{
int i = 0, j = 0;

while (dest[i] != '\0')
i++;

while (src[j] != '\0')
dest[i++] = src[j++];

dest[i] = '\0';
return (dest);
}


/**
* _strdup - duplicates a string (custom strdup)
* @str: the input string
* Return: pointer to newly allocated copy
*/
char *_strdup(const char *str)
{
char *copy;
int len, i;

if (!str)
return (NULL);

len = _strlen(str);
copy = malloc(sizeof(char) * (len + 1));
if (!copy)
return (NULL);

for (i = 0; i <= len; i++)
copy[i] = str[i];

return (copy);
}

/**
* _strncmp - compares n characters of two strings
* @s1: string 1
* @s2: string 2
* @n: number of characters to compare
* Return: difference
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
while (n && *s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
n--;
}
if (n == 0)
return (0);
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char *_strcpy(char *dest, const char *src)
{
int i = 0;

if (dest == NULL || src == NULL)
return (NULL);

while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}
