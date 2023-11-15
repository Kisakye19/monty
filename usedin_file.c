#include "monty.h"

/**
 * f_open - opens a file
 * @f_name: the file namepath
 * Return: void
 */

void f_open(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err(2, f_name);

	f_read(fd);
	fclose(fd);
}


/**
 * f_read - reads a file
 * @fd: pointer to file descriopor
 * Return: void
 */

void f_read(FILE *fd)
{
	int line_number, form_t = 0;
	char *buf = NULL;
	size_t length = 0;

	for (line_number = 1; getline(&buf, &length, fd) != -1; line_number++)
	{
		form_t = tokenize(buf, line_number, form_t);
	}
	free(buf);
}


/**
 * tokenize - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @line_number: line number
 * @form_t:  storage form_t. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int tokenize(char *buf, int line_number, int form_t)
{
	char *opcode, *val;
	const char *delimeter = "\n ";

	if (buf == NULL)
		err(4);

	opcode = strtok(buf, delimeter);
	if (opcode == NULL)
		return (form_t);
	val = strtok(NULL, delimeter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	search_func(opcode, val, line_number, form_t);
	return (form_t);
}

/**
 * search_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @form_t:  storage form_t. If 0 Nodes will be entered as a stack.
 * @line: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void search_func(char *opcode, char *val, int line, int form_t)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", handle_stack},
		{"pint", handle_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", handle_char},
		{"pstr", handle_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			get_func(func_list[i].f, opcode, val, line, form_t);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, line, opcode);
}


/**
 * get_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric val.
 * @line: line number for the instruction.
 * @form_t: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void get_func(op_func func, char *op, char *val, int line, int form_t)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, line);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, line);
		}
		node = create_node(atoi(val) * flag);
		if (form_t == 0)
			func(&node, line);
		if (form_t == 1)
			add_to_queue(&node, line);
	}
	else
		func(&head, line);
}
