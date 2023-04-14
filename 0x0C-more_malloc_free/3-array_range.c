#include "main.h"
/**
 * array_range - function that creates an array of chars,
 *  and initializes it with a specific char
 * @min: first bytes of the memory
 * @max: first bytes of the memory
 * Return: pointer to the resulting string dests
 */
int *array_range(int min, int max)
{
	int *z;
	int i;

	if (min > max)
		return (NULL);
	z = malloc((max - min + 1) * sizeof(int));
	if (z == NULL)
		return (NULL);
	for (i = 0; i <= max - min; i++)
	{
		z[i] = min + i;
	}
	return (z);
}
