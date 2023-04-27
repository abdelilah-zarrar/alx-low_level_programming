#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list_t list
 * @str: string to be added to the new node
 *
 * Return: pointer to the new head of the list_t list
 *         NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new_node;
unsigned int len;

if (!head || !str)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

len = 0;
while (str[len])
len++;

new_node->str = strdup(str);
new_node->len = len;
new_node->next = *head;

*head = new_node;

return (new_node);
}
