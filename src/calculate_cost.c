#include "../include/push_swap.h"

bool calculate_rotations(t_stack *stack, t_stack *node)
{
    int size;
    int index;

    if (stack == NULL || node == NULL) 
    {
        return (false);
    }
    size = 0;
    list_size(stack, &size);
    if (size == 0)
    {
        return (false);
    }
    index = node->index;
    if (index < 0 || index >= size)
    {
        return (false);
    }
    if (index <= size / 2)
    {
        node->cost = index;
        node->direction =  eFORWARD;
    }
    else
    {
        node->cost = size - index;
        node->direction = eBACKWARD;
    }
    return (true);
}

bool    calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *node_b;
    t_stack *node_a;

    if (stack_b == NULL)
    {
        fprintf(stderr, "Error: stack_b is NULL.\n");
        return (false);
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
    return (true);
}
