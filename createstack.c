#include "monty.h"
/**
 * is_number - function that iterates each
 * character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}
/**
 * push - function that adds node to the start of dlinkedlist
 * @head: head of linked list (node at the bottom of stack)
 * @line: bytecode line number
 * @n: integer
 */
void push(stack_t **head, unsigned int line, const char *n)
{
	if (!head)
		return;
	if (is_number(n) == -1)
	{
		printf("L%u: usage: push integer\n", line);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(head, atoi(n)) == -1)
		{
			free_dlist(head);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pop - functio that removes node at front of dlinkedlist
 * @head: head of linked list (node at the bottom of stack)
 * @line: bytecode line number
 */
void pop(stack_t **head, unsigned int line)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line);
		free_dlist(head);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(head);
}
