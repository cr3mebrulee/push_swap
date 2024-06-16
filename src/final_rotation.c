#include "../include/push_swap.h"

t_stack    *rotation_settings(t_stack *stack)
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
    return (stack);
}

void    reverse_rotate(int i, t_stack **stack)
{
    while (i > 0)
    {
        rra(stack);
        i--;
    }
    return ;
}

void    rotate(int i, t_stack **stack)
{
    while (i > 0)
    {
        ra(stack);
        i--;
    }
    return ;
}

void    final_rotation(t_stack **stack)
{
    int i;
    int size;
    int middle;
    t_stack *minimum;
    
    i = 0;
    minimum = rotation_settings(*stack);
    list_size(*stack, &size);
    middle = size / 2;
    if (minimum->index <= middle)
    {
        i = minimum->index;
        rotate(i, stack);
    }
    else if (minimum->index > middle)
    {
        i = size - minimum->index;
        reverse_rotate(i, stack);
    }
    return ;
}