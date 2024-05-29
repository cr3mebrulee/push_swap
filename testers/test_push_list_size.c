

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:19:14 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 15:19:51 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <assert.h>

static void	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}

void	test_push100(void)
{
	t_stack	*stack;
	t_stack	*temp;
	int 	out_size;

	out_size = 0;
	stack = NULL;
	for (int i = 0; i < 100; i++)
	{
		push(&stack, i);
	}
	assert(stack->data == 99);
	assert(stack->next->data == 98);
	list_size(stack, &out_size);
	assert(out_size == 100);
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	test_push2(void)
{
	t_stack	*stack;
	int	out_size;

	stack = NULL;
	out_size = 0;
	push(&stack, 16);
	push(&stack, 17);
	assert(stack->data == 17);
	assert(stack->next->data == 16);
	list_size(stack, &out_size);
	assert(out_size == 2);
}

void test_push1(void)
{
	t_stack *stack;
	int	out_size;

	stack = NULL;
	out_size = 0;
	push(&stack, 15);
	assert(stack->data == 15);
	list_size(stack, &out_size);
	assert(out_size == 1);
}

int	main()
{
	test_push1();
	test_push2();
	test_push100();
}
