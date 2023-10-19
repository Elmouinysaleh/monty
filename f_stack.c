#include "monty.h"
/**
  *f_nop- nothing
  *@head: head of stack
  *@counter: number of lines
  *Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
/**
 * f_push - add node to the stack
 * @head: head of the stack
 * @counter: number of lines
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
  int n, j = 0, flag = 0;

  if (bus.arg)
  {
    if (bus.arg[0] == '-')
      j++;
    for (; bus.arg[j] != '\0'; j++)
    {
      if (bus.arg[j] > 57 || bus.arg[j] < 48)
        flag = 1; }
    if (flag == 1)
    { fprintf(stderr, "L%d: usage: push integer\n", counter);
      fclose(bus.file);
      free(bus.content);
      free_stack(*head);
      exit(EXIT_FAILURE); }}
  else
  { fprintf(stderr, "L%d: usage: push integer\n", counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE); }
  n = atoi(bus.arg);
  if (bus.lifi == 0)
    addnode(head, n);
  else
    addqueue(head, n);
}
/**
 * f_pop - prints the top
 * @head: head of stack
 * @counter:  number of line
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
  stack_t *h;

  if (*head == NULL)
  {
    fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
  }
  h = *head;
  *head = h->next;
  free(h);
}
/**
 * f_pall - prints the given stack
 * @head: head of stack
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
  stack_t *h;
  (void)counter;

  h = *head;
  if (h == NULL)
    return;
  while (h)
  {
    printf("%d\n", h->n);
    h = h->next;
  }
}
/**
 * f_stack - prints the top
 * @head: head of the given stack
 * @counter: number of line
 * Return: no return
*/
void f_stack(stack_t **head, unsigned int counter)
{
  (void)head;
  (void)counter;
  bus.lifi = 0;
}
