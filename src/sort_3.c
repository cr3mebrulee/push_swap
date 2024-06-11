#include "../include/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	first_num;
	int	second_num;
	int	third_num;

	first_num = (*stack_a)->data;
	second_num = (*stack_a)->next->data;
	third_num = (*stack_a)->next->next->data;
	if ((first_num > second_num) && (first_num < third_num))
		sa(stack_a);
	else if ((first_num < second_num) && (first_num > third_num))
		rra(stack_a);
	else if ((first_num > second_num) && (second_num < third_num))
		ra(stack_a);
	else if ((first_num > second_num) && (second_num > third_num))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((first_num < second_num) && (second_num > third_num))
	{
		sa(stack_a);
		ra(stack_a);
	}
}
