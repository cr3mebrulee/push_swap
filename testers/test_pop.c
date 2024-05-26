/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:30:26 by taretiuk          #+#    #+#             */
/*   Updated: 2024/05/18 18:15:33 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

void	test_push100(void)
{
	t_stack	*stack;
	int 	out_size;
	int		value;

	out_size = 0;
	stack = NULL;
	for (int i = 0; i < 100; i++)
	{
		push(&stack, i);
	}
	print_stack(stack);
	list_size(stack, &out_size);
	ft_printf("Size stack before pop: %d\n", out_size);
	while (out_size > 3)
	{
		value = pop(&stack);
		out_size--;
	}
	list_size(stack, &out_size);
	ft_printf("Size stack after pop: %d\n", out_size);
	assert(value == 3);
	if (value == 3)
	{
		ft_printf("Last pop element is 4 as expected.\n");
	}
	else
	{
		ft_printf("Last pop element is 4 as expected.\n");
	}
}

void	test_push2(void)
{
	t_stack	*stack;
	int	out_size;
	int	value;

	stack = NULL;
	out_size = 0;
	push(&stack, 16);
	push(&stack, 17);
	value = pop(&stack);
	assert(value == 17);
	if (value == 17)
	{
		ft_printf("pop returned 17 as expected.\n");
	}
	else
	{
		ft_printf("pop did not return 17 as expected.\n");
	}
	value = pop(&stack);
	assert(value == 16);
	if (value == 16)
	{
		ft_printf("pop returned 16 as expected.\n");
	}
	else
	{
		ft_printf("pop did not return 16 as expected.\n");
	}
}

void	test_push1(void)
{
	t_stack	*stack;
	int	out_size;
	int	value;

	stack = NULL;
	out_size = 0;
	value = pop(&stack);
	assert(value == -1);
	if (value == -1)
	{
		ft_printf("pop returned -1 as expected.\n");
	}
	else
	{
		ft_printf("pop did not return -1 as expected.\n");
	}
}

int	main()
{
	test_push1();
	test_push2();
	test_push100();
}
