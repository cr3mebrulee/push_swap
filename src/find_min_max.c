#include "../include/push_swap.h"

bool    find_max(t_stack *stack, int *num)
{
    *num = stack->data;
    while (stack) 
    {
        if (stack->data > *num)
        {
            *num = stack->data;
        }     
        stack = stack->next;
    }
    return (true);
}

bool find_min(t_stack *stack, int *num)
{
    *num = stack->data;
    while (stack) 
    {
        if (stack->data < *num)
        {
            *num = stack->data;
        }     
        stack = stack->next;
    }
    return (true);
}