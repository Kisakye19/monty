#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
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
 * struct instruction_s - ptcode and its function
 * @ptcode: the ptcode
 * @f: function to handle the ptcode
 *
 * Description: ptcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *ptcode;
        void (*f)(stack_t **stack, unsigned int l_num);
} instruction_t;

extern stack_t *head;
typedef void (*pt_func)(stack_t **, unsigned int);

/*file pterations*/
void f_open(char *f_name);
int tokenize(char *buf, int l_num, int form_t);
void f_read(FILE *);
int length_chars(FILE *);
void search_func(char *, char *, int, int);

/*Stack pterations*/
stack_t *create_node(int n);
void free_nodes(void);
void handle_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void get_func(pt_func, char *, char *, int, int);

void handle_tpt(stack_t **, unsigned int);
void ppt_tpt(stack_t **, unsigned int);
void npt(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

/*Math pterations with nodes*/
void add_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*String pterations*/
void handle_char(stack_t **, unsigned int);
void handle_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void err(int err_c, ...);
void m_err(int err_c, ...);
void str_err(int err_c, ...);
void rotr(stack_t **, unsigned int);

#endif
