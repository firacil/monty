#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct help - argument for opcode
 * @datas: stack mode.
 * @argus: arguments of string.
 */
typedef struct help
{
	int datas;
	char *argus;
} help;
help global;

/* Prototypes */

void runner(stack_t **stack, char *str, unsigned int line_no);
int is_digit(char *string);
stack_t *addn(stack_t **stack, const int n);
stack_t *qnod(stack_t **stack, const int n);
void free_stack(stack_t *head);

/* Instructions */
size_t print_stack(const stack_t *stack);
void pall(stack_t **stack, unsigned int line_no);
void push(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
#endif
