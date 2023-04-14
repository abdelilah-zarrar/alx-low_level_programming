#include "main.h"
/**
 * _calloc - function that creates an array of chars,
 *  and initializes it with a specific char
 * @nmemb: first bytes of the memory
 * @size: first bytes of the memory
 * Return: pointer to the resulting string dests
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *z;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	z = malloc(nmemb * size);
	if (z == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
	{
		z[i] = 0;
	}
	return (z);
}
