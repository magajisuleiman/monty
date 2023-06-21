#include "monty.h"



/**
 * swap - function that swap locations of previous stack with the top stack
 * @head: node to be swapped
 * @line: node number
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *tmp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	if (tmp->next != NULL)
	{
		(*head)->next = tmp->next;
		(*head)->next->prev = *head;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *head;
	(*head) = tmp;
}
/**
 * rotl - function ttack becomes last one, second becomes first one
 * @head: node to be rotated
 * @line: node number
 */
void rotl(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	(void) line;

	if ((*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*head)->prev = tmp;
		tmp->next = *head;
		(*head)->next->prev = NULL;
		*head = (*head)->next;
		tmp->next->next = NULL;
	}
}
/**
 * rotr - function that rotate so only bottom node of stack becomes first one
 * @head: node to be rotated
 * @line: node number
 */
void rotr(stack_t **head, unsigned int line)
{
	stack_t *tmp;

	(void) line;

	if ((*head)->next != NULL)
	{
		tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*head)->prev = tmp;
		tmp->next = *head;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*head) = (*head)->prev;
	}
}
