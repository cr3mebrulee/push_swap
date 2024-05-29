#include "../include/push_swap.h"

void    find_max(t_stack *stack, int *num)
{
    while(stack->next != NULL)
    {
        stack = stack->next;
    }
    *num = stack->data;
}

void find_middle_node(t_stack *stack, int middle, t_stack **middle_node) 
{
    int count;
    
    count = 0;
    while (stack && count < middle) 
    {
        stack = stack->next;
        *middle_node = stack;
        count++;
    }
    return ;
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

void    target_under_middle(t_stack *stack, t_stack *node, int number, int *index)
{
    while (node != NULL && node->next != NULL)
    {
        if (node->data < number && node->next->data > number)
        {
            find_index(stack, node->next->data, index);
            return ;
        }
        node = node->next;
    }
}

void    target_between_max_min(t_stack *stack, int number, int *index)
{
    int size;
    int middle;
    t_stack *middle_node;
    
    list_size(stack, &size);
    middle = size / 2;
    find_middle_node(stack, middle, &middle_node);
    if (number < middle_node->data)
    {
        target_above_middle(stack, number, index, middle_node->data);
    }
    if (number > middle_node->data)
    {
        target_under_middle(stack, middle_node, number, index);
    }
}

/*process three possible cases: a number less than the min, 
a number greater than the max, and a number between the min and max values.*/
void find_target_index(t_stack *stack, int number, int *index)
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