/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:33:22 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 13:26:57 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	list_size(t_stack *stack, int *out_size)
{
	int	i;
	t_stack	*ptr;

	if (!stack)
	{
		return (-1);
	}
	i = 0;
	ptr = stack;
	while(ptr != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	*out_size = i;
	return (0);
}
