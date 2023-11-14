#include "monty.h"

/**
 * mul_nodes - Adds the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void mul_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		m_err(8, l_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the tpt two elements of the stack.
 * @stack: Pointer to a pointer pointing to tpt node of the stack.
 * @l_num: Interger representing the line number of of the ptcode.
 */
void mod_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		m_err(8, l_num, "mod");


	if ((*stack)->n == 0)
		m_err(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
