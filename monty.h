#ifndef MONTY_H
#define MONTY_H

#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


/* data structures */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* opcodes related prototypes */
void pstr(stack_t **head, unsigned int line);
void rotl(stack_t **head, unsigned int line);
void rotr(stack_t **head, unsigned int line);
void (*get_op_func(char *token1))(stack_t **stack, unsigned int line_number);
void push(stack_t **head, unsigned int line, const char *n);
void pop(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);
void pchar(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pall(stack_t **head, unsigned int line);


/* calculator prototypes */
void _div(stack_t **head, unsigned int line);
void _mul(stack_t **head, unsigned int line);
void _mod(stack_t **head, unsigned int line);
void _add(stack_t **head, unsigned int line);
void _sub(stack_t **head, unsigned int line);

/* doubly linked list related prototypes */
void free_dlist(stack_t **head);
int add_end_node(stack_t **head, int n);
void delete_end_node(stack_t **head);


#endif
