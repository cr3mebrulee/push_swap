#include "../include/push_swap.h"

void calculate_rotations(t_stack *stack, t_stack *node)
{
    int size;
    int index;
    t_stack *ptr;
    
    size = 0;
    ptr = stack;
    while (ptr != NULL) 
    {
        size++;
        ptr = ptr->next;
    }
    index = node->index;
    if (index <= size / 2)
    {
        node->cost = index;
        node->direction = 0;
    }
    else
    {
        node->cost = size - index;
        node->direction = 1;
    }
}

void    calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *node_b;
    t_stack *node_a;

    if (stack_b == NULL)
    {
        fprintf(stderr, "Error: stack_b is NULL.\n");
        return ;
    }
    node_b = stack_b;
    node_a = stack_a;
    while (node_b != NULL)
    {
        find_index(stack_b, node_b->data);
        calculate_rotations(stack_b, node_b);
        find_target_index(stack_a, node_b->data, &node_a);
        node_b->target_index = node_a->index;
        calculate_rotations(stack_a, node_a);
        node_b->sum_cost = node_b->cost + node_a->cost;
        node_b = node_b->next;
        node_a = stack_a;
    }
    return ;
}
