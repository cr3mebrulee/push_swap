/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:57:21 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 19:19:36 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	push_stack_b(stack_a, stack_b);
	if (!if_sorted(*stack_a))
	{
		sort_3(stack_a);
	}
	push_stack_a(stack_a, stack_b);
	if (!if_sorted(*stack_a))
	{
    	final_rotation(stack_a);
	}
    return (0);
}

int	choose_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	out_size;

	out_size = 0;
	list_size(*stack_a, &out_size);
	if (out_size == 3)
	{
		sort_3(stack_a);
	}
	else if (out_size == 2)
	{
		sa(stack_a);
	}
	else
	{
        sort_large_stack(stack_a, stack_b);
	}
	return (0);
}
