#include "../include/push_swap.h"

t_stack *find_last_node(t_stack *stack) 
{
    if (stack == NULL) 
    {
        return (NULL);
    }
    
    t_stack *current = stack;
    while (current->next != NULL) 
    {
        current = current->next;
    }
    return (current);
}

bool number_between_min_max(t_stack *stack, int number, t_stack **target)
{
    int i;
    t_stack *node;

    node = stack;
    i = 0;
    while (node != NULL && node->next != NULL)
    {
        if (node->data < number && node->next->data > number)
        {
            find_index(stack, node->next->data);
            *target = node->next;
            return (true);
        }
        node = node->next;
        i++;
    }
    return (false);
}
        

int new_min_or_max(t_stack *stack, int min, t_stack **target)
{
    int i;
    
    i = 0;
    while (stack != NULL)
    {
        if (stack->data == min)
        {
            stack->index = i;
            *target = stack;
            return (true);
        }
        stack = stack->next;
        i++;
    }
    return(false);
}

bool find_target_index(t_stack *stack, int number, t_stack **target)
{
    t_stack *node;
    t_stack *last_node;
    int min;
    int max;

    last_node = find_last_node(stack);
    find_min(stack, &min);
    find_max(stack, &max);
    node = stack;
    if (number < min || number > max) 
    {
        new_min_or_max(stack, min, target);
    }
    else if (number < stack->data && number > last_node->data)
    {
        node->index = 0;
        *target = node;
        return (true);
    }
    else
    {
        number_between_min_max(stack, number, target);
    }
    return (false); 
}