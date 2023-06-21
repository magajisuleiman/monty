#include "monty.h"



/**
 * main - function entry into interpreter
 * @argc: argc counter
 * @argv: arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_d;
	int ispushs = 0;
	unsigned int lines = 1;
	ssize_t n_read;
	char *buff, *tkn;
	stack_t *h = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_d = open(argv[1], O_RDONLY);
	if (file_d == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buff = malloc(sizeof(char) * 10000);
	if (!buff)
		return (0);
	n_read = read(file_d, buff, 10000);
	if (n_read == -1)
	{
		free(buff);
		close(file_d);
		exit(EXIT_FAILURE);
	}
	tkn = strtok(buff, "\n\t\a\r ;:");
	while (tkn != NULL)
	{
		if (ispushs == 1)
		{
			push(&h, lines, tkn);
			ispushs = 0;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			lines++;
			continue;
		}
		else if (strcmp(tkn, "push") == 0)
		{
			ispushs = 1;
			tkn = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (get_op_func(tkn) != 0)
			{
				get_op_func(tkn)(&h, lines);
			}
			else
			{
				free_dlist(&h);
				printf("L%d: unknown instruction %s\n", lines, tkn);
				exit(EXIT_FAILURE);
			}
		}
		lines++;
		tkn = strtok(NULL, "\n\t\a\r ;:");
	}
	free_dlist(&h);
	free(buff);
	close(file_d);
	return (0);
}
