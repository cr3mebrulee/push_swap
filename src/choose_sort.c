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

void	choose_sort(t_stack *stack_a, t_stack *stack_b)
{
	int out_size;

	out_size = 0;
	if (list_size(stack_a, &out_size) == -1)
	{
		ft_printf("Error");
		return ;
	}
	if (out_size == 3)
	{
		sort_3(&stack_a);
	}
	else if (out_size == 2)
	{
		sa(&stack_a);
	}
	else
	{
		push_stack_b(&stack_a, &stack_b);
		if (!if_sorted(stack_a))
		{
			sort_3(&stack_a);
		}
		push_stack_a(&stack_a, &stack_b);
		if (!if_sorted(stack_a))
		{
			final_rotation(&stack_a);
		}
		
	}
}
