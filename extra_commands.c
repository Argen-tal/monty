#include "monty.h"

/**
* mod - opcode that mods the top two elements
* @stack: the stack
* @line_number: the line mumber
*/

void mod(stack_t **stack, unsigned int line_number)
{
  if (list_len(*stack) < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
((*stack)->next)->n %= (*stack)->n;
delete_at_index(stack, 0);
}
