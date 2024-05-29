#include "../include/push_swap.h"

void    find_max(t_stack *stack, int *num)
{
    while(stack->next != NULL)
    {
        stack = stack->next;
    }
    *num = stack->data;
}

void    target_above_middle(t_stack *stack, int number, int *index, int middle_value)
{
    while (number < middle_value && stack->next != NULL)
    {
        if (stack->data < number && stack->next->data > number)
        {
            find_index(stack, stack->next->data, index);
            return ;
        }
        stack = stack->next;
    }
}

void    target_under_middle(t_stack *stack, int number, int *index)
{
    while (stack != NULL && stack->next != NULL)
    {
        if (stack->data < number && stack->next->data > number)
        {
            find_index(stack, stack->next->data, index);
            return ;
        }
        stack = stack->next;
    }
}

void find_middle_value(t_stack *stack, int middle, int *middle_value) 
{
    int current = 0;

    while (stack != NULL) 
    {
        if (current == middle) 
        {
            *middle_value = stack->data;
            return ;
        }
        stack = stack->next;
        current++;
    }
}

void    target_between_max_min(t_stack *stack, int number, int *index)
{
    int size;
    int middle;
    int middle_value;
    
    list_size(stack, &size);
    middle = size / 2;
    find_middle_value(stack, middle, &middle_value);
    if (number <= middle_value)
    {
        target_above_middle(stack, number, index, middle_value);
    }
    if (number > middle_value)
    {
        target_under_middle(stack, number, index);
    }
}

/*process three possible cases: a number less than the min, 
a number greater than the max, and a number between the min and max values.*/
void find_target_node(t_stack *stack, int number, int *index)
{
    t_stack *tmp;
    int min;
    int max;
    
    tmp = stack;
    min = tmp->data;
    find_max(tmp, &max);
    if (number < min)
    {
        find_index(tmp, min, index);
    }
    else if (number > max)
    {
        find_index(tmp, max, index);
    }
    else
    {
        target_between_max_min(tmp, number, index);
    }
    return ;
}