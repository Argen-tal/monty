#include "monty.h"

/**
* add_dnodeint - adds a new node at the beginning of a list
* @head: the pointer to the head
* @n: the value of the new node
*
* Return: the address of the new element on success,
* Otherwise: NULL
*/

stack_t *add_dnodeint(stack_t **head, const int n)
{
stack_t *new_node;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
return (NULL);
}
new_node->n = n;
if (*head)
{
(*head)->prev = new_node;
new_node->next = *head;
}
*head = new_node;
return (*head);
}

/**
* add_dnodeint_end - adds a new node at the end of the list
* @head: a pointer to the head of the list
* @n: the value of the new node
*
* Return: the address of the new element on success,
* Otherwise: NULL
*/

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
stack_t *new_node, *trav;

trav = head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
return (NULL);
}
new_node->n = n;
if (*head)
{
while ((trav)->next != NULL)
{
trav = (trav)->next;
}
trav->next = new_node;
new_node->prev = trav;
}
else
{
*head = new_node;
}
return (new_node);
}

/**
* print_list - prints all the elements of a list
* @h: a pointer to the head of the list
*
* Return: the number of nodes
*/

size_t print_list(const stack_t *h)
{
const stack_t *trac = h;
int count = 0;

while (trav)
{
printf("%d\n", trav->n);
trav = trav->next;
count++;
}
return (count);
}

/**
* delete_at_index - delete a node at a position
* @head: the pointer
* @index: the position to be deleted
*
* Return: 1 on success, -1 on failure
*/

int delete_at_index(stack_t **head, unsigned int index)
{
stack_t *trav, *temp;
unsigned int i = 0;

if (*head == NULL)
return (-1);
if (index == 0)
{
temp = (*head)->next;
if (temp != NULL)
temp->prev = NULL;
free((*head));
*head = temp;
return (1);
}

trav = *head;
while (i < index)
{
if (trav == NULL)
return (-1);
trav = trav->next;
i++;
}
temp = trav;
(trav->prev)->next = trav->next;
if (trav->next != NULL)
(trav->next)->prev = trav->prev;
free(trav);
return (1);
}

/**
* list_len - return the number of elements
* @h: the pointer
*
* Return: the number of elements
*/

size_t list_len(const stack_t *h)
{
const stack_t *trav = h;
int count = 0;

while (trav)
{
trav = trav->next;
count++;
}
return (count);
}
