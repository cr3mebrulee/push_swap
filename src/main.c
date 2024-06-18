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

int	check_number_arguments(int argc, char **array)
{
	if (argc == 1 || (argc == 2 && !array[1][0]))
	{
		exit (-1);
	}
	return (0);
}

int	parse_second_argument(char *str, t_stack **stack)
{
	char	**split_argv;

	split_argv = ft_split(str, ' ');
	if (split_argv == NULL)
	{
		error_split(split_argv);
	}
	if (create_stack_a(stack, split_argv) == -1)
	{
		error_create_stack(split_argv, stack);
	}
	free_2d_array(split_argv);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_number_arguments(argc, argv);
	if (argc == 2)
	{
		parse_second_argument(argv[1], &stack_a);
	}
	else
	{
		if (create_stack_a(&stack_a, argv + 1) == -1)
		{
			ft_printf("Error\n");
			free_stack(&stack_a);
			exit(-1);
		}
	}
	if (!if_sorted(stack_a))
	{
		choose_sort(&stack_a, &stack_b);
	}
	// printf("Main\n");
	// print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}