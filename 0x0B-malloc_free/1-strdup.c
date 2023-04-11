#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicates a string
 * @str: pointer to string to duplicate
 *
 * Return: pointer to newly allocated memory containing the duplicated string
 *         NULL if str is NULL or if memory allocation fails
 */
char *_strdup(char *str)
{
char *dup;
unsigned int len, i;

if (str == NULL)
return (NULL);

/* get length of str */
for (len = 0; str[len]; len++)
	;

/* allocate memory for duplicate string */
dup = malloc(sizeof(char) * (len + 1));

if (dup == NULL)
return (NULL);

/* copy string to new memory */
for (i = 0; i <= len; i++)
dup[i] = str[i];

return (dup);
}
