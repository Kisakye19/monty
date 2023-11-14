#include "monty.h"

/**
 * npt - Does nothing.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void npt(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}


/**
 * swap_nodes - Swaps the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void swap_nodes(stack_t **stack, unsigned int l_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, l_num, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - Adds the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void add_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, l_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void sub_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		m_err(8, l_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void div_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, l_num, "div");

	if ((*stack)->n == 0)
		m_err(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
