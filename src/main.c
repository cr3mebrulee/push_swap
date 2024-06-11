/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:23:20 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 18:15:54 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Function to print stack*/
void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split_argv;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		create_stack_a(&stack_a, split_argv);
	}
	else
	{
		create_stack_a(&stack_a, argv + 1);
	}
	if (!if_sorted(stack_a))
	{
		choose_sort(stack_a, stack_b);
	}
	print_stack(stack_a);
	return (0);
}