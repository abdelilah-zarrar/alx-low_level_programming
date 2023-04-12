#include "main.h"
#include <stdlib.h>

/**
* argstostr - concatenates all the arguments of the program
* @ac: the number of arguments
* @av: an array of strings containing the arguments
*
* Return: a pointer to the new string, or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
int i, j, k = 0, len = 0;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
len++; /* add space for the newline character */
}

str = malloc(sizeof(char) * len);
if (str == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[k] = av[i][j];
k++;
}
str[k] = '\n';
k++;
}

return (str);
}
