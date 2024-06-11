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

static int	ft_atol(const char *str)
{
	long int	result;
	int			sign;

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
		{
			printf("Usage: expected integer");
			exit (1);
		}
			
		result = (*str - '0') + (result * 10);
		str++;
	}
	if ((result > LONG_MAX || result < LONG_MIN)
		|| (result > INT_MAX || result < INT_MIN))
	{
		ft_printf("Usage: expected integer\n");
		exit(-1);
	}
	return (result * sign);
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
				return (false);
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

void	add_node_to_end(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
	{
		return ;
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
}

void	create_stack_a(t_stack **stack, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		add_node_to_end(stack, num);
		i++;
	}
	if (!if_dubles(*stack))
	{
		ft_printf("Usage: expected uniq numbers\n");
		exit(-1);	 
	}
}
