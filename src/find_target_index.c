#include "../include/push_swap.h"

bool    find_max(t_stack *stack, int *num)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Error: stack is NULL.\n");
        return (false);
    }

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
    if (!stack) 
    {
      return (false);
    }
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

bool find_target_index(t_stack *stack, int number, t_stack **target)
{
    t_stack *node;
    t_stack *last_node;
    int min;
    int max;
    int i;
    
    i = 0;
    last_node = find_last_node(stack);
    find_min(stack, &min);
    find_max(stack, &max);
    node = stack;
    if (number < min || number > max) 
    {
        while (node != NULL)
        {
            if (node->data == min)
            {
                node->index = i;
                *target = node;
                return (0);
            }
            node = node->next;
            i++;
        }
    }
    else if (number < stack->data && number > last_node->data)
    {
        node->index = i;
        *target = node;
        return (true);
    }
    else
    {
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
    }
    return (true); 
}