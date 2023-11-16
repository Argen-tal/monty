#include "monty.h"

/**
* insert_at_index - inserts a nose at a position
* @h: the pointer
* @idx: the position where to insert
* @n: the data
*
* Return: the address of the new node
* Otherwise: NULL
*/

stack_t *insert_at_index(stack_t **h, unsigned int idx, int n)
{
  stack_t *trav, *new_node, *temp;
unsigned int i = 0;

if (idx == 0)
  return (add_dnodeint(h, n));
trav = *h;
while (i < (idx - 1))
{
if (trav == NULL)
  return (NULL);
trav = trav->next;
i++;
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
return (NULL);
}

new_node->n = n;
if (trav->next == NULL)
{
return (add_dnodeint_end(h, n));
}
else
{
trav = trav->next;
new_node->next = trav;
new_node->prev = trav->prev;
temp = trav;
(trav->prev)->next = new_node;
temp->prev = new_node;
}
return (new_node);
}
