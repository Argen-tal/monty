#include "monty.h"

/**
* exec - helps with the execution of the opcode
* @line: the line
* @line_number: the line number of the opcode
* @rack: the stack to be used
*/

void exec(char *line, unsigned int line_number, stack_t **rack)
{
  int j, arg;
char *token, token1;
instruction_t commands[] = {
{"push", push}, {"pall", pall}, {"pint", pint},
{"pop", pop}, {"swap", swap}, {"add", add},
{"nop", nop}, {"sub", sub}, {"mul", mul},
{"div", divide}, {"mod", mod}
};

token = strtok(line, " \n");
token1 = strtok(NULL, " ");

j = 10;
while (j > -1)
{
if (token == NULL)
  return;
if (strcmp(commands[j].opcode, token) == 0)
  break;
j--;
}
if (j == -1)
{
fprintf(stderr, "L%d: unknwon instruction %s\n", line_number, token);
exit(EXIT_FAILURE);
}

if (token1 == NULL)
  arg = -1;
else
{
arg = atoi(token1);
if (arg != 0)
  global_arg = arg;
else if (check_atoi(token1) == 0)
  global_arg = 0;
else
  global_arg = -1;
}
commands[j].f(rack, line_number);
}

/**
* check_atoi - check for bug of zero atoi
* @str: the string
* Return: 0 if successful, otherwise 1
*/

int check_atoi(char *str)
{
  char *ptr = str;
int i = 0;

while (ptr[i] == ' ')
  i++;
if (*ptr == '0')
  return (0);
else
  return (1);
}

/**
* rm_newline - gets getline content to be ready
* @nline: getline content
* @nread: the length
*
* Return: pointer to the command line
*/

char *rm_newline(char *nline, ssize_t nread)
{
  char *line;

line = malloc(sizeof(char) * nread);
strcpy(line, nline);
line[nread - 1] = '\0';
return (line);
}
