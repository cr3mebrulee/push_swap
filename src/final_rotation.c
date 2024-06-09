#include "../include/push_swap.h"

void    rotation_settings(t_stack *stack)
{
    int min;
    int i;

    find_min(stack, &min);
    i = 0;
    while(stack != NULL)
    {
        if (stack->data == min)
        {
            stack->index = i;
            break;
        }
        i++;
        stack = stack->next;
    }
    return ;
}

void    final_rotation(t_stack **stack)
{
    int i;
    int size;
    int middle;
    t_stack *tmp;
    
    i = 0;
    tmp = *stack;
    list_size(*stack, &size);
    middle = size / 2;
    rotation_settings(*stack);
    if (tmp->index <= middle)
    {
        i = tmp->index;
        while (i >= 0)
        {
            ra(stack);
            i--;
        }
        write(1, "not_sorted: ra\n", 15);
        print_stack(*stack);
    }
    else if (tmp->index > middle)
    {
        i = size - tmp->index;
        while (i > 0)
        {
            rra(stack);
            i--;
        }
        write(1, "not_sorted: rra\n", 16);
        print_stack(*stack);
    }
    return ;
}