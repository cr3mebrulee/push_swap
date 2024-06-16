/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:00:18 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 19:24:24 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		/*+ handle error*/
		return ;
	}
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	write(1, "sa\n", 3);
}

void	rra(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	t_stack	*second_last;
	t_stack	*last;

	second_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	write(1, "rra\n", 4);
}

void	ra(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	t_stack	*first;
	t_stack	*current;

	first = *stack;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	*stack = first->next;
	first->next = NULL;
	current->next = first;
	write(1, "ra\n", 3);
}