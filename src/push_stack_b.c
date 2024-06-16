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

bool	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		return (false);
	}
	new_node->data = value;
	new_node->next = *stack;
	*stack = new_node;
	return (true);
}

bool	pop(t_stack **stack, int *value)
{
	t_stack *temp;

	if (!*stack)
	{
		return (false);
	}
	temp = *stack;
	*value = temp->data;
	*stack = (*stack)->next;
	free(temp);
	return (true);
}

int	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	int	size;

	size = 0;
	list_size(*stack_a, &size);
	while (size > 3)
	{
		if (pop(stack_a, &value) != 0)
		{
			push(stack_b, value);
			write(1, "pb\n", 3);
			size--;
		}
		else 
		{
			ft_printf("Error\n");
			free_stack(stack_b);
			free_stack(stack_a);
		}
	}
	return (0);
}
