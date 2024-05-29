/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 09:45:55 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 17:37:32 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	pop(t_stack **stack, int *value)
{
	if (!*stack)
		return (-1);

	t_stack *temp;

	temp = *stack;
	*value = temp->data;
	*stack = (*stack)->next;
	free(temp);
	return (0);
}

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	int	size;

	size = 0;
	list_size(*stack_a, &size);
	while (size > 3)
	{
		pop(stack_a, &value);
		push(stack_b, value);
		size--;
	}
	printf("Stack b:\n");
	print_stack(*stack_b);
	printf("Stack a after pushing stack b:\n");
	print_stack(*stack_a);
}
