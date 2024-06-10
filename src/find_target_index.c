#include "../include/push_swap.h"

void    find_max(t_stack *stack, int *num)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Error: stack is NULL.\n");
        return;
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
}

void find_min(t_stack *stack, int *num)
{
  if (!stack) return;
    *num = stack->data;
    while (stack) 
    {
        if (stack->data < *num)
        {
            *num = stack->data;
        }     
        stack = stack->next;
    } 
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

/*process three possible cases: a number less than the min or more than max, 
a number between first and last node, and a number between first and last node values.*/
void find_target_index(t_stack *stack, int number, t_stack **target)
{
    t_stack *node;
    t_stack *last_node;
    int min;
    int max;
    /*variable for index incrementing*/
    int i;
    
    i = 0;
    last_node = find_last_node(stack);
    /*find minimum value in stack*/
    find_min(stack, &min);
    /*find max value in stack*/
    find_max(stack, &max);
    /*make copy of stack for safty*/
    node = stack;
    /*if number is new min or new max we put it on top of min*/
    if (number < min || number > max) 
    {
        while (node != NULL)
        {
            if (node->data == min)
            {
                node->index = i;
                /*old minimum is our target, we return it to the call function*/
                *target = node;
                return ;
            }
            node = node->next;
            i++;
        }
    }
    else if (number < stack->data && number > last_node->data)
    {
        node->index = i;
        *target = node;
        return;
    }
    /*we work on case when target is between max and min values of stack*/
    else
    {
        while (node != NULL && node->next != NULL)
        {
            /*if number more then current node but less than next - next one is our target
            ! we didn't consider case when number should be inserted between 1st and last nodes
            what lead to mistakes*/
            if (node->data < number && node->next->data > number)
            {
                find_index(stack, node->next->data);
                *target = node->next;
                return ;
            }
            node = node->next;
            i++;
        }
    }   
    return ; 
}