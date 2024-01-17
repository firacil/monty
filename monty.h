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
 * struct stream_s - variable holder.
 * @st: File that connect stream from file.
 * @line: string that is line of the text read from stream
 *
 * Description: it is variables holder that will
 * be used in functions for project.
 */
typedef struct stream_s
{
	FILE *st;
	char *line;
	unsigned int line_no;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	int stack;
        int stlen;
} stream_t;

extern stream_t *argus;

void check_arg(int argc);
void init_arg();
void mallocerr();
void read_fail(char *fn);
void free_args();
void read_it(char *fn);
void free_head(void);
void free_stack(stack_t *h);
void findins(void);
void insterr(void);
void free_tokens(void);
void stclosed(void);
void runin(void);
void tokenize(void);
int is_no(char *s);

/* prototype of Instructions */
void push(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);

#endif
