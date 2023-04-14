#include <stdlib.h>
#include "main.h"
#include <string.h>

/**
  * _realloc - reallocates a memory block using malloc and free
  * @ptr: pointer to the memory previsouly allocated by malloc
  * @old_size: size of the allocated memory for ptr
  * @new_size: new size of the new memory block
  * Return: pointer to the newly allocated memory block
  */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptt;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}

	if (new_size == old_size)
	{
		return (ptr);
	}

	new_ptt = malloc(new_size);

	if (new_ptt == NULL)
	{
		return (NULL);
	}

	if (new_size < old_size)
	{
		memcpy(new_ptt, ptr, new_size);
	}
	else
	{
		memcpy(new_ptt, ptr, old_size);
	}
	free(ptr);
	return (new_ptt);
}
