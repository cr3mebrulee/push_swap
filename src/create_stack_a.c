/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:33:30 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 09:05:26 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_long_bounderies(long int result)
{
	
	if ((result > LONG_MAX || result < LONG_MIN)
		|| (result > INT_MAX || result < INT_MIN))
	{
		return (false);
	}
	return (true);
}
	
bool	ft_atol(const char *str, long *num)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		result = (*str - '0') + (result * 10);
		str++;
	}
	result *= sign;
	if (!check_long_bounderies(result))
	{
		return (false);
	}
	*num = result;
	return (true);
}

bool	if_dubles(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		while (tmp != NULL)
		{
			if (stack->data == tmp->data)
			{
				return (false);
			}
		tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (true);
}

t_stack		*last_node(t_stack *stack)
{
	if (!stack)
	{
		return (NULL);
	}
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	add_node_to_end(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		return (-1);
	}
	new_node->next = NULL;
	new_node->data = num;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		last_node(*stack)->next = new_node;
	}
	return (0);
}

int	create_stack_a(t_stack **stack, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (!(ft_atol(argv[i], &num)))
		{
			return (-1);
		}
		if (add_node_to_end(stack, num) == -1)
		{
			ft_printf("Error\n");
			free_stack(stack);
			return (-1);
		}
		i++;
	}
	if (!if_dubles(*stack))
	{
		return (-1);
	}
	return (0);
}
