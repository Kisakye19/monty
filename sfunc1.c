#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line: Interger representing the line number of of the ptcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * handle_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: line number of  the ptcode.
 */
void handle_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * ppt_tpt - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void ppt_tpt(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		m_err(7, l_num);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * handle_tpt - Prints the tpt node of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void handle_tpt(stack_t **stack, unsigned int l_num)
{
	if (stack == NULL || *stack == NULL)
		m_err(6, l_num);
	printf("%d\n", (*stack)->n);
}
