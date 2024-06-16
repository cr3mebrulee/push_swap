#include "../include/push_swap.h"

void	rb(t_stack **stack)
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
	write(1, "rb\n", 3);
}

void	rrb(t_stack **stack)
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
	write(1, "rrb\n", 4);
}