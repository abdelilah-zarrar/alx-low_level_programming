#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to a newly allocated space in memory with the concatenated
 *         string or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
char *concat_str;
int s1_len = 0, s2_len = 0, i, j;

/* Handle NULL strings as empty strings */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

/* Find the lengths of the strings */
while (*(s1 + s1_len) != '\0')
s1_len++;
while (*(s2 + s2_len) != '\0')
s2_len++;

/* Allocate memory for the concatenated string */
concat_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
if (concat_str == NULL)
return (NULL);

/* Copy the contents of s1 and s2 into the concatenated string */
for (i = 0; i < s1_len; i++)
*(concat_str + i) = *(s1 + i);
for (j = 0; j < s2_len; j++)
*(concat_str + i + j) = *(s2 + j);

/* Add null terminator */
*(concat_str + i + j) = '\0';

return (concat_str);
}
